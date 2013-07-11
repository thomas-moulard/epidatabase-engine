/*
** main.h for epiDatabase
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  01/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#ifndef MAIN_H_
# define MAIN_H_

#define _POSIX_SOURCE_C 1

# include "types.h"
# include "signal.h"

# include "epiEngine/createdb.h"
# include "epiEngine/dropdb.h"
# include "epiEngine/createtbl.h"
# include "epiEngine/renametbl.h"

# include "locale/msg_index.h"
# include "locale/fr/msg.c"
# include "locale/en/msg.c"

struct s_sql_query  gl_query;
struct s_sql_result gl_result;

extern int yyparse(void);

void Release();

#endif /* !MAIN_H_ */
