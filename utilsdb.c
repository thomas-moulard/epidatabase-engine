/*
** createtbl.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  02/01/2005 assema_j
** Last update 25/02/2005 moular_t
*/

#include "utilsdb.h"
/* */

/*
** database exist?
*/
int databaseexist(const char* database)
{
    DIR *d;
    char path[255];
    
    if(*database==0)
       return(0);
    
    strcpy(path, PATH_DATA);
    strcat(path, "\\");
    strcat(path, database);
     
    d=opendir(path);
    if(d)
    {
       closedir(d);
       return(1);
    } else {
       closedir(d);
       return(0);
    }
}
