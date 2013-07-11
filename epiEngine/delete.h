/*
** delete.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  03/01/2005 moular_t
** Last update 26/02/2005 moular_t
*/

#ifndef DELETE_H_
# define DELETE_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

void deletetbl(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !DELETE_H_ */
