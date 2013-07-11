/*
** select.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   assema_j
**
** Started on  02/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#ifndef SELECT_H_
# define SELECT_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../types.h"
# include "../locale/msg_index.h"

void select(struct s_sql_query *query, struct s_sql_result *result);
p_ldata GetTableData(char * DatabaseName, char * TableName, p_table FieldsList);

#endif /* !SELECT_H_ */
