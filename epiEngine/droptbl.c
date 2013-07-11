/*
** droptbl.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 26/02/2005 moular_t
*/

#include "droptbl.h"

void droptable(struct s_sql_query *query, struct s_sql_result *result)
{
   FILE *f;
   char filename[S_TABLE+strlen(EXTENSION_TABLE)-1]; 
   char filename_data[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   
   printf("\t Drop table %s: %s\n",(query->if_exists?"(ignore if not exists)":"(error if not exists)"),getFirstTblName(query));
   
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
   if(!databaseexist(getFirstDbName(query)))
   {
      result->error_code=MSG_DATABASE_NOT_EXISTS;
      return;
   }
   

   *filename=0;
   *filename_data=0;
   
   strcpy(filename, PATH_DATA);
   strcat(filename, getFirstDbName(query));
   strcat(filename, "\\");
   strcat(filename, getFirstTblName(query));
   
   strcpy(filename_data,filename);
   strcat(filename, EXTENSION_TABLE);
   strcat(filename_data, EXTENSION_DATA);
     
   f=fopen(filename, "r");
   if(!f)
   {
      if(query->if_exists)
         result->error_code=MSG_OK;
      else
         result->error_code=MSG_TABLE_NOT_EXIST;
   }
   else
   {
      fclose(f);
      remove(filename);
      remove(filename_data);
      
      
      if((f=fopen(filename,"r")))
      {
         result->error_code=MSG_CANT_DELETE_TABLE;
         fclose(f);
      } else
         result->error_code=MSG_OK;
      }
}
