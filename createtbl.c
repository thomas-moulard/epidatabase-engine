/*
** createtbl.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 25/02/2005 moular_t
*/

#include "createtbl.h"

void createtable(struct s_sql_query *query, struct s_sql_result *result)
{
   FILE *f;
   char filename[255], filename_data[255]; 
   p_table tbl;
   
   printf("\t Create table %s %s\n",(query->if_not_exists?"(ignore if exists)":"(error if exists)"),getFirstTblName(query));

   if(getFirstDbName(query)==NULL)
   {
      result->error_code=MSG_INVALID_DATABASE_NAME;
      return;
   }   
   if(getFirstTblName(query)==NULL)
   {
      result->error_code=MSG_INVALID_TABLE_NAME;
      return;
   }
   if(query->nbcols <= 0)
   {
      result->error_code=MSG_INVALID_CREATE_TABLE_DEFINITION; /* 0 column... */
      return;
   }
   if(!databaseexist(getFirstDbName(query)))
   {
      result->error_code=MSG_DATABASE_NOT_EXISTS;
      return;
   }

   *filename = 0;
   *filename_data = 0;
   
   strcpy(filename, PATH_DATA);
   strcat(filename, getFirstDbName(query));
   strcat(filename, "\\");
   strcat(filename, getFirstTblName(query));
   
   strcpy(filename_data, filename);
   
   strcat(filename, EXTENSION_TABLE);
   strcat(filename_data, EXTENSION_DATA);
   
   if((f = fopen(filename_data, "w")))  
        fclose(f);
     
   f = fopen(filename, "r");
   if(!f)
   {
     f = fopen(filename, "w");
     
     tbl = query->table;
     while(tbl!=NULL)
     {
        fwrite(&tbl->column, sizeof(struct s_column), 1, f);
        tbl=tbl->next;
     }
     fclose(f);
     
     result->error_code=MSG_OK;
   }
   else
   {
     fclose(f);
     
     if(query->if_not_exists)
        result->error_code=MSG_OK;
     else
        result->error_code=MSG_TABLE_EXISTS;
   }
}

void AddColumnDefinition(char* name, struct s_sql_query *query)
{   
     p_table elt, cur_elt;
     elt = calloc(1, sizeof(struct s_table));
     
     strcpy(elt->column.name,name);
     elt->column.size=0;
     elt->column.flags=FLAG_NULL;
     memset(&elt->column.def_value, 0, sizeof(struct s_univdata));
     elt->next=NULL;
     
     if(!query->table)
        query->table=elt;
     else {
        cur_elt=query->table;
        while(cur_elt->next)
           cur_elt=cur_elt->next;
        cur_elt->next=elt;
     }
     query->nbcols++;
}

void SetColumnDefinitionType(unsigned char type, struct s_sql_query *query)
{
     p_table cur_elt;
     
     cur_elt=query->table;
     if(cur_elt)
     {
        while(cur_elt->next)
           cur_elt=cur_elt->next;
        cur_elt->column.type=type;
     }
}


void SetColumnDefinitionSize(int size, struct s_sql_query *query)
{    
     p_table cur_elt;
     
     cur_elt=query->table;
     if(cur_elt)
     {
        while(cur_elt->next)
           cur_elt=cur_elt->next;
        cur_elt->column.size=size;
     }
}

void SetColumnDefinitionFlag(int mask, int flagv, struct s_sql_query *query)
{
     p_table cur_elt;
     
     cur_elt=query->table;
     if(cur_elt)
     {
        while(cur_elt->next)
           cur_elt=cur_elt->next;
       
        if(!flagv)
           cur_elt->column.flags &= ~mask;
        else
           cur_elt->column.flags |= mask;
     }
}

void SetColumnDefaultValue(struct s_univdata default_value, struct s_sql_query *query)
{
     p_table cur_elt;
     
     cur_elt=query->table;
     if(cur_elt)
     {
        while(cur_elt->next)
           cur_elt=cur_elt->next;
         cur_elt->column.def_value=default_value;
     }
}
