/*
** optimize.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  02/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#ifndef OPTIMIZE_H_
# define OPTIMIZE_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "utilsdb.h"
# include "utilstbl.h"

# include "../types.h"
# include "../locale/msg_index.h"

void optimizetable(struct s_sql_query *query, struct s_sql_result *result);

#endif /* !OPTIMIZE_H_ */
