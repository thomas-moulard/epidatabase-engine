/*
** createtbl.h for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  02/01/2005 assema_j
** Last update 25/02/2005 moular_t
*/

#ifndef UTILSDB_H_
# define UTILSDB_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>

# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

int databaseexist(const char* database);

#endif /* !UTILSDB_H_ */
