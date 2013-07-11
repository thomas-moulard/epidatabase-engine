/*
** update.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  03/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#ifndef UPDATE_H_
# define UPDATE_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../types.h"
# include "../locale/msg_index.h"

void update(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !UPDATE_H_ */
