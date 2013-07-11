/*
** createdb.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 24/02/2005 moular_t
*/

#include "createdb.h"

void createdatabase(struct s_sql_query *query, struct s_sql_result *result)
{
     DIR* d;
     char path[255];
     
     printf("\t Create DB %s %s\n",(query->if_not_exists?"(ignore if exists)":"(error if exists)"), getFirstDbName(query));
     
     if(getFirstDbName(query)==NULL)
     {
        result->error_code=MSG_INVALID_DATABASE_NAME;
        return;
     }

     strcpy(path, PATH_DATA);
     strcat(path, "\\");
     strcat(path,  getFirstDbName(query));
     
     d=opendir(path);
     if(d)
     {
        closedir(d);
        if(query->if_not_exists)
                result->error_code=MSG_OK; /* IF NOT EXISTS => NO ERROR */
        else
                result->error_code=MSG_DATABASE_EXISTS;
     }
     else
     {
        mkdir(path);
        strcpy(query->default_dbname,getFirstDbName(query)); /* is default db */
        result->error_code=MSG_OK;
     }
}
