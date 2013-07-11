/*
** use.c for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  23/02/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#include "use.h"

void usedb(struct s_sql_query *query, struct s_sql_result *result)
{
   printf("\t Database %s selected\n", getFirstDbName(query));
   
   if( !databaseexist(getFirstDbName(query)) )
      result->error_code = MSG_DATABASE_NOT_EXISTS;
   else {
      strcpy(query->default_dbname,getFirstDbName(query));
      result->error_code = MSG_OK;
   }
}
