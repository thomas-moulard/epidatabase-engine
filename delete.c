/*
** delete.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  03/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#include "delete.h"

void deletetbl(struct s_sql_query *query, struct s_sql_result *result)
{
   FILE *f;
   char filename[S_TABLE+strlen(EXTENSION_TABLE)-1]; 
   char filename_data[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   
   printf("\t Delete from %s\n",getFirstTblName(query));
   
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
   *filename_data = 0;
   
   strcpy(filename, PATH_DATA);
   strcat(filename, getFirstDbName(query));
   strcat(filename, "\\");
   strcat(filename, getFirstTblName(query));
   
   strcpy(filename_data, filename);
   
   strcat(filename, EXTENSION_TABLE);
   strcat(filename_data, EXTENSION_DATA);
   
   if((f=fopen(filename,"r")))
      fclose(f);
   else {
      result->error_code=MSG_TABLE_NOT_EXIST;
      return;
   }
   
   
   /* IF NO CONDITION */
   if((f=fopen(filename_data,"w")))
   {
      fclose(f);
      result->error_code = MSG_OK;
   } else
      result->error_code=MSG_CANT_DELETE_TABLE_DATA;

}
