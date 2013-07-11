/*
** signal.h for epiDatabase
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on 23/02/2005 moular_t
** Last update 23/02/2005 moular_t
*/

#ifndef SIGNAL_H_
# define SIGNAL_H_

# include <stdio.h>
# include <signal.h>

# include "types.h"
# include "main.h"

extern struct s_sql_query  gl_query;
extern struct  s_sql_result gl_result;

void epiDatabaseParachute(int no);
void signalInterruption(int no);

void setupSignals();

#endif /* !SIGNAL_H_ */
