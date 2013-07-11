/*
** show_columns.h for epiDatabase in /epiEngine
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  25/02/2005 moular_t
** Last update 25/02/2005 moular_t
*/

#ifndef SHOW_COLUMNS_H_
# define SHOW_COLUMNS_H_

# include <stdio.h>

# include "utilsdb.h"
# include "utilstbl.h"

# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

void show_columns(struct s_sql_query *query, struct s_sql_result *result);
p_table GetTableDefinition(char *database, char *table);
void freeTableDefinition(p_table table);

#endif /* !SHOW_COLUMNS_H_ */
