/*
** check.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   assema_j
**
** Started on  02/01/2005 moular_t
** Last update 02/01/2005 moular_t
*/

#ifndef CHECK_H_
# define CHECK_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../types.h"
# include "../locale/msg_index.h"

void checktable(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !CHECK_H_ */
