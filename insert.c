/*
** insert.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  02/01/2005 moular_t
** Last update 26/02/2005 moular_t
*/

#include "insert.h"
#include "../const.h"

/* Add value to data list for insert request */
void AddData(struct s_univdata ins_data, struct s_sql_query *query)
{
    p_ldata elt, cur_elt;
        
    elt = calloc(1, sizeof(struct s_ldata));
    elt->data=ins_data;
    elt->next = NULL;
    
    if(!query->datalist)
       query->datalist=elt;
    else {
       cur_elt=query->datalist;
       while(cur_elt->next)
          cur_elt=cur_elt->next;
       cur_elt->next=elt;
    }
}
void AddDataVide(struct s_sql_query *query)
{
   struct s_univdata ins_data;
   ins_data.type=VIDE;
   AddData(ins_data,query);
}

void insert(struct s_sql_query *query, struct s_sql_result *result)
{
   p_ldata Temp;
   FILE * f;
   char filename_data[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   
   char tempValue;
   int i,endOfString;
   long start, row_size;
   
   p_table tbl_struct, cur_col;
   
   printf("\t Insert into table %s\n",getFirstTblName(query));
   
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
   
   
   *filename_data = 0;
   
   strcpy(filename_data, PATH_DATA);
   strcat(filename_data, getFirstDbName(query));
   strcat(filename_data, "\\");
   strcat(filename_data, getFirstTblName(query));
   strcat(filename_data, EXTENSION_DATA);
   
   if((f = fopen(filename_data, "a+")))
   {
        start=ftell(f);
        tbl_struct=GetTableDefinition(getFirstDbName(query), getFirstTblName(query));
        
        Temp = query->datalist;
        cur_col=tbl_struct;
        
        while(cur_col && Temp)
        {
            Temp = Temp->next;
            cur_col=cur_col->next;
        }
        if(cur_col||Temp)
        {
           result->error_code=MSG_COLUMN_COUNT_NOT_MATCH;
           return;
        }
        
        /* Size of the complete row? */
        cur_col=tbl_struct;
        row_size=0;
        while(cur_col)
        {
            row_size += cur_col->column.size;
            cur_col=cur_col->next;
        }
        
        Temp = query->datalist;
        cur_col=tbl_struct;
        
        while(cur_col && Temp)
        {
            /* CAST */
            /* END OF CAST */
                        
            if(Temp->data.type==VIDE)
            {
               if( (cur_col->column.flags & FLAG_NULL) == 0)
               { /* COLUMN NOT NULL => DELETE CURRENT ROW */
                   ClearRow(f,start, row_size);
                   result->error_code=MSG_FIELD_CANT_BE_NULL;
                   fclose(f);
                   return;
               } else {
                  tempValue=0;
                  fwrite(&tempValue,sizeof(char),cur_col->column.size,f); /* fill with 0 */
               }
            }
            else if(Temp->data.type==ENTIER)
            {
               if(colType2basicType(cur_col->column.type) != ENTIER)
               { /* WRONG TYPE => FILL WITH 0 */
                  tempValue=0;
                  fwrite(&tempValue,sizeof(char),cur_col->column.size,f); /* fill with 0 */
               } else {
                    tempValue=Temp->data.data.number;
                  for(i=0;i<cur_col->column.size;i++)
                  { /* write until the column is not complete => truncate int */
                     tempValue=Temp->data.data.number%sizeof(char);
                     fwrite(&tempValue,sizeof(char),1,f); 
                     Temp->data.data.number /= sizeof(char);
                  }
               }
            }
            else if(Temp->data.type==FLOTTANT)
            {
                 if(sizeof(double)!=cur_col->column.size) /* need same size, can't truncate */
                 {
                    tempValue=0;
                    fwrite(&tempValue,sizeof(char),cur_col->column.size,f); /* fill with 0 */
                 } else {
                    fwrite(&Temp->data.data.floatNumber,sizeof(double),1,f);
                 }
            }
            else if(Temp->data.type==CHAINE)
            {
               if(colType2basicType(cur_col->column.type) != ENTIER)
               { /* WRONG TYPE => FILL WITH 0 */
                  tempValue=0;
                  fwrite(&tempValue,sizeof(char),cur_col->column.size,f); /* fill with 0 */
               } else {
                  /* copy string until the column is not complete => truncate string */
                  endOfString=0;
                  for(i=0;i<cur_col->column.size;i++)
                  {
                     if((endOfString=0)&&(Temp->data.data.string[i]==0)) endOfString=i;
                     tempValue=endOfString?Temp->data.data.string[endOfString]:Temp->data.data.string[i];
                     fwrite(&tempValue,sizeof(char),1,f);
                     Temp->data.data.number /= sizeof(char);
                  }
               }
            }
            Temp = Temp->next;
            cur_col=cur_col->next;
        } 
        freeTableDefinition(tbl_struct);
        fclose(f);
        result->error_code = MSG_OK;
   } else
        result->error_code = MSG_CANT_ACCESS_TABLE_DATA;
}
