/*
** select.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  02/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#include "select.h"
#include "utilstbl.h"
#include "show_columns.h"

p_ldata GetTableData(char * DatabaseName, char * TableName, p_table FieldsList)
{
    FILE *f;
    union u_data DataBuffer;
    p_ldata DataList, *Temp;

    char filename[S_TABLE+strlen(EXTENSION_TABLE)-1];
    
    *filename = 0;
    strcpy(filename, PATH_DATA);
    strcat(filename, DatabaseName);
    strcat(filename, "\\");
    strcat(filename, TableName);
    strcat(filename, EXTENSION_DATA);
    f = fopen(filename, "r");
    if(f)
    {
        DataList = NULL;
        while(!feof(f))
        {
            *Temp = calloc(1, sizeof(struct s_ldata));
            if(colType2basicType(FieldsList->column.type) == ENTIER)
            {
                fread(&(DataBuffer.number),1,FieldsList->column.size,f);
                (*Temp)->data.data.number = DataBuffer.number;
                (*Temp)->next = NULL;
                Temp = &((*Temp)->next);
            }
            else if(colType2basicType(FieldsList->column.type) == FLOTTANT)
            {
                fread(&(DataBuffer.floatNumber),1,FieldsList->column.size,f);
                (*Temp)->data.data.floatNumber = DataBuffer.floatNumber;
                (*Temp)->next = NULL;
                Temp = &((*Temp)->next);
            }
            else
            {
                fread(&(DataBuffer.string),1,FieldsList->column.size,f);
                *((*Temp)->data.data.string) = 0;
                strcpy((*Temp)->data.data.string, DataBuffer.string);
                (*Temp)->next = NULL;
                Temp = &((*Temp)->next);
            }
            FieldsList = FieldsList->next;
        }
        fclose(f);
    }
    
    return(DataList);
}

void select(struct s_sql_query *query, struct s_sql_result *result)
{
    p_table FieldsList;
    /*p_ldata DataList;*/
    
    if(!databaseexist(getFirstDbName(query)))
    {
       result->error_code=MSG_DATABASE_NOT_EXISTS;
       return;
    }
    if(!tableexist(getFirstDbName(query),getFirstTblName(query)))
    {
       result->error_code=MSG_TABLE_NOT_EXIST;
       return;
    }

    init_p_table(&FieldsList);
    FieldsList = GetTableDefinition(getFirstDbName(query), getFirstTblName(query));
    /*DataList = GetTableData(getFirstDbName(query), getFirstTblName(query), FieldsList);*/
    
    printf("Champs valides (0=invalide / 1=OK) : %d\n", IsInTable(FieldsList, query->fieldlist));

    if(IsInTable(FieldsList, query->fieldlist))
    {
        printf("\t Select from table %s\n",getFirstTblName(query));   
        result->error_code = MSG_OK;
    }
    else
        result->error_code = MSG_INVALID_COLUMN_NAME;
        
    freeTableDefinition(FieldsList);
}
