/*
** createtbl.h for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  01/01/2005 assema_j
** Last update 25/02/2005 moular_t
*/

#ifndef CREATETBL_H_
# define CREATETBL_H_

# include <stdio.h>
# include <string.h>

# include "utilstbl.h"
# include "utilsdb.h"

# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

void createtable(struct s_sql_query *query, struct s_sql_result *result);

void AddColumnDefinition(char* name, struct s_sql_query *query);
void SetColumnDefinitionType(unsigned char type, struct s_sql_query *query);
void SetColumnDefinitionSize(int size, struct s_sql_query *query);
void SetColumnDefinitionFlag(int mask, int flagv, struct s_sql_query *query);
void SetColumnDefaultValue(struct s_univdata default_value, struct s_sql_query *query);

#endif /* !CREATETBL_H_ */
