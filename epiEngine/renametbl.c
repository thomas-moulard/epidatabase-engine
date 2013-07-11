/*
** renametbl.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 24/02/2005 moular_t
*/

#include "renametbl.h"

void renametbl(struct s_sql_query *query, struct s_sql_result *result)
{
   p_lident lident;
   
   char filename_src[S_TABLE+strlen(EXTENSION_TABLE)-1]; 
   char filename_data_src[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   char filename_dest[S_TABLE+strlen(EXTENSION_TABLE)-1]; 
   char filename_data_dest[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   
   printf("\t Rename table to %s\n",getFirstTblName(query));
   
   lident=query->identlist;
   
   if(lident)
      while(lident->next)
      {
         *filename_src      = 0;
         *filename_data_src = 0;
   
         strcpy(filename_src, PATH_DATA);
         strcat(filename_src, lident->db_name);
         strcat(filename_src, "\\");
         strcat(filename_src, lident->tbl_name);
   
         strcpy(filename_data_src, filename_src);
   
         strcat(filename_src, EXTENSION_TABLE);
         strcat(filename_data_src, EXTENSION_DATA);
         lident=lident->next;
         
         *filename_dest      = 0;
         *filename_data_dest = 0;
   
         strcpy(filename_dest, PATH_DATA);
         strcat(filename_dest, lident->db_name);
         strcat(filename_dest, "\\");
         strcat(filename_dest, lident->tbl_name);
   
         strcpy(filename_data_dest, filename_dest);
   
         strcat(filename_dest, EXTENSION_TABLE);
         strcat(filename_data_dest, EXTENSION_DATA);
         
         rename(filename_src,filename_dest);
         rename(filename_data_src,filename_data_dest);
         
         if(lident->next) lident=lident->next;
      }
   
   result->error_code = MSG_OK;
}
