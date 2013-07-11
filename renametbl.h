/*
** renametbl.h for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 24/02/2005 moular_t
*/

#ifndef RENAMETBL_H_
# define RENAMETBL_H_

# include <stdio.h>

# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

void renametbl(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !RENAMETBL_H_ */
