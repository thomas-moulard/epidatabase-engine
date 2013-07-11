/*
** insert.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   assema_j
**
** Started on  02/01/2005 moular_t
** Last update 26/02/2005 moular_t
*/

#ifndef INSERT_H_
# define INSERT_H_

# include <stdio.h>

# include "show_columns.h"
# include "utilstbl.h"
# include "utilsdb.h"

# include "../types.h"
# include "../locale/msg_index.h"

void insert(struct s_sql_query *query, struct s_sql_result *result);
void AddData(struct s_univdata ins_data, struct s_sql_query *query);
void AddDataVide(struct s_sql_query *query);

#endif /* !INSERT_H_ */
