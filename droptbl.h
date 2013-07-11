/*
** droptbl.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  01/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#ifndef DROPTBL_H_
# define DROPTBL_H_

# include <stdio.h>
# include <string.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../types.h"
# include "../const.h"
# include "../locale/msg_index.h"

void droptable(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !DROPDB_H_ */
