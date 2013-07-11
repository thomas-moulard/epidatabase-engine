/*
** optimize.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  02/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#include "optimizetbl.h"

void optimizetable(struct s_sql_query *query, struct s_sql_result *result)
{
   printf("\t Optimize table %s\n",getFirstTblName(query));
   
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
   
   result->error_code = MSG_OK;
}
