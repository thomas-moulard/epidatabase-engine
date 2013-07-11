/*
** dropdb.h for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 24/02/2005 moular_t
*/

#ifndef DROPDB_H_
# define DROPDB_H_

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>

# include "utilsdb.h"

# include "../types.h"
# include "../const.h"
# include "../locale/msg_index.h"

void dropdatabase(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !DROPDB_H_ */
