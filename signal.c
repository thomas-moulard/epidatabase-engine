/*
** signal.c for epiDatabase
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  23/02/2005 moular_t
** Last update 23/02/2005 moular_t
*/

#include "signal.h"


void epiDatabaseParachute(int no)
{
     fprintf(stderr, "epiDatabase: Segmentation fault (epiDatabase parachute deployed)");
     init_sql_query(&gl_query);
     /* FIXME: free result */
     
     fflush(stdout);
     fflush(stderr);
     return;
}

void signalInterruption(int no)
{
   Release();
   return;
}

void setupSignals()
{
     signal(SIGSEGV, epiDatabaseParachute);
     signal(SIGINT,  signalInterruption);
}
