/*
** createtbl.h for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  02/01/2005 assema_j
** Last update 26/02/2005 moular_t
*/

#ifndef UTILSTBL_H_
# define UTILSTBL_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "show_columns.h"
# include "../const.h"
# include "../types.h"
# include "../locale/msg_index.h"

int tableexist(const char* database, const char *table);
void ClearRow(FILE *f, long start, long size);
e_basic_type colType2basicType(int colType);
void AddColumnToList(struct s_sql_query *query, char * ColumnName, char * TableName, char * DatabaseName);
int IsInTable(p_table List1, p_lfield List2);

p_lrow init_result(struct s_sql_query *query);
void free_result(p_lrow result);
void filter_comparison(p_lrow *result, struct s_univdata lexp, struct s_univdata rexp, char comparison, struct s_sql_query *query);
void DebugShowWhereResult(p_lrow where_res);

#endif /* !UTILSTBL_H_ */
