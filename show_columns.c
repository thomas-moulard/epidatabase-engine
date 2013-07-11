/*
** show_columns.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  02/01/2005 moular_t
** Last update 25/02/2005 moular_t
*/

#include "show_columns.h"

void show_columns(struct s_sql_query *query, struct s_sql_result *result)
{
    FILE *f;
    
    char filename[S_TABLE+strlen(EXTENSION_TABLE)-1];
    struct s_column col;
    
    printf("\t Show columns %s\n",getFirstTblName(query));
    
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
    
    *filename = 0;
    strcpy(filename, PATH_DATA);
    strcat(filename, getFirstDbName(query));
    strcat(filename, "\\");
    strcat(filename, getFirstTblName(query));
    strcat(filename, EXTENSION_TABLE);
    f = fopen(filename, "r");
    if(f)
    {
        printf("=== STRUCTURE - %s - ===\n", getFirstTblName(query));
        while(!feof(f))
        {
           *col.name=0;
           fread(&col,1,sizeof(struct s_column),f);
           
           if(*col.name != 0)
           {
              printf("%s %d(%d) [%#x]",col.name, col.type, col.size, col.flags);
              
              if(col.def_value.type==ENTIER)
                 printf("Default value: %d",col.def_value.data.number);
              else if(col.def_value.type==FLOTTANT)
                 printf("Default value: %f",col.def_value.data.floatNumber);
/*
              else  if(col.def_value.type==CHAINE)
                 printf("Default value: %s",col.def_value.data);
*/
              
              printf("\n");
           }
        }
        printf("=== FIN STRUCTURE ===\n");

        result->error_code = MSG_OK;    
        fclose(f);
    }
    else
        result->error_code = MSG_TABLE_NOT_EXIST;    
}

p_table GetTableDefinition(char *database, char *table)
{
    FILE *f;
    p_table res,elt,prec;
    
    char filename[S_TABLE+strlen(EXTENSION_TABLE)-1];
    struct s_column col;
    
    res=prec=elt=NULL;
    
    *filename = 0;
    strcpy(filename, PATH_DATA);
    strcat(filename, database);
    strcat(filename, "\\");
    strcat(filename, table);
    strcat(filename, EXTENSION_TABLE);
    f = fopen(filename, "r");
    if(f)
    {
        while(!feof(f))
        {
           *col.name=0;
           fread(&col,1,sizeof(struct s_column),f);
           if(*col.name!=0)
           {
              elt=malloc(sizeof(struct s_table));
              elt->column=col;
              elt->next=NULL;
              if(prec!=NULL)
                  prec->next=elt;
              else
                  res=elt;
              prec=elt;
           }
        }
        fclose(f);
    }
    
    return(res);
}

void freeTableDefinition(p_table table)
{
   p_table next;
   while(table)
   {
      next=table->next;
      free(table);
      table=next;
   }
}
