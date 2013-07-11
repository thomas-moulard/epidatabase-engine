/*
** dropdb.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 24/02/2005 moular_t
*/

#include "dropdb.h"

void dropdatabase(struct s_sql_query *query, struct s_sql_result *result)
{
     DIR *d;
     struct dirent *dp;
     
     char path[255];
     char path_table[255];
    
     printf("\t Drop database %s: %s\n",(query->if_exists?"(ignore if not exists)":"(error if not exists)"),getFirstDbName(query));
     
     if(getFirstDbName(query)==NULL)
     {
        result->error_code=MSG_INVALID_DATABASE_NAME;
        return;
     }

     strcpy(path, PATH_DATA);
     strcat(path, "\\");
     strcat(path, getFirstDbName(query));
     
     d=opendir(path);
     if(d)
     {
        dp=readdir(d);
        while(dp)
        {
           *path_table=0;
           strcpy(path_table, path);
           strcat(path_table, "\\");
           strcat(path_table, dp->d_name);
           remove(path_table);
           dp=readdir(d);
        }
        closedir(d);
        rmdir(path);
        *query->default_dbname=0;
        result->error_code=MSG_OK;
     }
     else
     {
        *query->default_dbname=0;
         if(query->if_exists)
            result->error_code=MSG_OK; /* DB DOESN'T EXIST => NO ERROR */
         else
            result->error_code=MSG_DATABASE_NOT_EXISTS;
     }     
}
