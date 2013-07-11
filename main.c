/*
** main.c for epiDatabase
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  01/01/2005 moular_t
** Last update 24/02/2005 moular_t
*/

#include "main.h"

int main()
{  
   setupSignals();
   init_sql_query(&gl_query);
   init_sql_result(&gl_result);
   while(1)
   {
      yyparse();
   }
  

    return 0;
}

void Release()
{
     printf("epiDatabase is going down...\n");
     reinit_sql_query(&gl_query);
     
     abort(); /* FIXME: trouver qqc de moins violent! */
     return;
}
