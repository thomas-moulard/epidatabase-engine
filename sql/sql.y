%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "../main.h"

#include "../epiEngine/checktbl.h"
#include "../epiEngine/createdb.h"
#include "../epiEngine/createtbl.h"
#include "../epiEngine/delete.h"
#include "../epiEngine/dropdb.h"
#include "../epiEngine/droptbl.h"
#include "../epiEngine/insert.h"
#include "../epiEngine/optimizetbl.h"
#include "../epiEngine/renametbl.h"
#include "../epiEngine/select.h"
#include "../epiEngine/show_columns.h"
#include "../epiEngine/update.h"
#include "../epiEngine/use.h"
#include "../epiEngine/utilsdb.h"
#include "../epiEngine/utilstbl.h"

#define FREE_DATA(x) if(x.type==CHAINE) { free(x.data.string); x.type=ENTIER; } else if(x.type==COLONNE_REF) { free(x.data.col_ref); x.type=ENTIER; }

extern char *strdup(const char*);

extern int yylex();
int yydebug=0;

extern struct s_sql_query  gl_query;
extern struct  s_sql_result gl_result;

void yyerror(const char *str)
{
   gl_result.error_code=MSG_SYNTAX_ERROR;
   fprintf(stderr, "error: %s\n", str);
   fflush(stdin);
}

int yywrap()
{
   return 1;
}

void end_query(void)
{ 
   printf("\tRESULT: %s [epiEngine has returned %d] \n", (gl_result.error_code==0)?"SUCCESS":"ERROR", gl_result.error_code);
   
   /* DEBUG 
   printf("### DEBUG ###\n");
   DebugShowIdentList(&gl_query);
   printf("Default database: %s\n", gl_query.default_dbname);
   printf("### END DEBUG ###\n");
   END DEBUG */
   
   reinit_sql_query(&gl_query);
   reinit_sql_result(&gl_result);
}

%}

%token TOKADD TOKALL TOKALTER TOKANALYSE TOKAS TOKASC TOKASENSITIVE
%token TOKBEFORE TOKBETWEEN TOKBIGINT TOKBINARY TOKBLOB TOKBOTH TOKBINARYTOKBLOB TOKBOTH TOKBY
%token TOKCALL TOKCASCADE TOKCASE TOKCHANGE TOKCHAR TOKCHARACTER TOKCHECK TOKCOLLATE TOKCOLUMN TOKCOLUMNS TOKCONDITION TOKCONNECTION TOKCONSTRAINT TOKCONTINUE TOKCONVERT TOKCREATE TOKCROSS
%token TOKCURRENT_DATE TOKCURRENT_TIME TOKCURRENT_TIMESTAMP TOKCURRENT_USER TOKCURSOR
%token TOKDATABASE TOKDATABASES TOKDATE TOKDATETIME TOKDAY_HOUR TOKDAY_MICROSECOND TOKDAY_MINUTE TOKDAY_SECOND TOKDEC TOKDECIMAL TOKDECLARE TOKDEFAULT TOKDELAYED TOKDELETE TOKDESC TOKDESCRIBE TOKDETERMINISTIC TOKDISTINCT TOKDISTINCTROW TOKDIV TOKDOUBLE TOKDROP TOKDUAL
%token TOKEACH TOKELSE TOKELSEIF TOKENCLOSED TOKESCAPED TOKEXISTS TOKEXIT TOKEXPLAIN
%token TOKFALSE TOKFETCH TOKFLOAT TOKFOR TOKFORCE TOKFOREIGN TOKFROM TOKFULLTEXT
%token TOKGOTO TOKGRANT TOKGROUP
%token TOKHAVING TOKHIGH_PRIORITY TOKHOUR_MICROSECOND TOKHOUR_MINUTE TOKHOUR_SECOND
%token TOKIF TOKIGNORE TOKIN TOKINDEX TOKINFILE TOKINNER TOKINOUT TOKINSENSITIVE TOKINSERT TOKINT TOKINTEGER TOKINTERVAL TOKINTO TOKIS TOKITERATE
%token TOKJOIN
%token TOKKEY TOKKEYS TOKKILL
%token TOKLEADING TOKLEAVE TOKLEFT TOKLIKE TOKLIMIT TOKLINES TOKLOAD TOKLOCALTIME TOKLOCALTIMESTAMP TOKLOCK TOKLONG TOKLONGBLOB TOKLONGTEXT TOKLOOP TOKLOW_PRIORITY
%token TOKMATCH TOKMEDIUMBLOB TOKMEDIUMINT TOKMEDIUMTEXT TOKMIDDLEINT TOKMINUTE_MICROSECOND TOKMINUTE_SECOND TOKMOD TOKMODIFIES
%token TOKNATURAL TOKNO_WRITE_TO_BINLOG TOKNULL TOKNUMERIC
%token TOKON TOKOPTIMIZE TOKOPTION TOKOPTIONALLY TOKORDER TOKOUT TOKOUTER TOKOUTFILE
%token TOKPRECISION TOKPRIMARY TOKPROCEDURE TOKPURGE
%token TOKREAD TOKREADS TOKREAL TOKREFERENCES TOKREGEXP TOKRENAME TOKREPEAT TOKREPLACE TOKREQUIRE TOKRESTRICT TOKRETURN TOKREVOKE TOKRIGHT TOKRLIKE
%token TOKSCHEMA TOKSCHEMAS TOKSECOND_MICROSECOND TOKSELECT TOKSENSITIVE TOKSEPARATOR TOKSET TOKSHOW TOKSMALLINT TOKSONAME TOKSPATIAL TOKSPECIFIC TOKSQL TOKSQLEXCEPTION TOKSQLSTATE TOKSQLWARNING TOKSQL_BIG_RESULT TOKSQL_CALC_FOUND_ROWS TOKSQL_SMALL_RESULT TOKSSL TOKSTARTING TOKSTRAIGHT_JOIN
%token TOKTABLE TOKTABLES TOKTERMINATED TOKTEXT TOKTHEN TOKTIME TOKTIMESTAMP TOKTINYBLOB TOKTINYINT TOKTINYTEXT TOKTO TOKTRAILING TOKTRIGGER TOKTRUE
%token TOKUNDO TOKUNION TOKUNIQUE TOKUNLOCK TOKUNSIGNED TOKUPDATE TOKUSAGE TOKUSE TOKUSING TOKUTC_DATE TOKUTC_TIME TOKUTC_TIMESTAMP
%token TOKVALUES TOKVARBINARY TOKVARCHAR TOKVARCHARACTER TOKVARYING
%token TOKWHEN TOKWHERE TOKWHILE TOKWITH TOKWRITE
%token TOKXOR
%token TOKYEAR_MONTH
%token TOKZEROFILL

%token DOT SEMICOLON STRING FLOAT INTEGER IDENT VIRGULE PARENTHESEOPEN PARENTHESECLOSE

%union
{
double floatNumber;
int number;
char *string;
char subtok;

struct s_univdata data;
p_lrow where_clause;
}

%left OR
%left AND
%left NOT
%left PLUS MINUS TIMES DIVIDE
%nonassoc UMINUS

%token <string>      STRING
%token <floatNumber> FLOAT
%token <number>      INTEGER
%token <string>      IDENT
%token <subtok>      COMPARISON /* < > <> <= >= */

%type <data>  scalar_exp atom literal column_ref
%type <where_clause> condition predicate comparison_predicate between_predicate like_predicate test_for_null in_predicate existence_test

%start commands

%%

commands:
  command { end_query(); } SEMICOLON 
| commands command { end_query(); } final_semicolon
;

final_semicolon:
/* empty */
| SEMICOLON
;

command:
check_table
|
create_database
|
create_table
|
deletetbl
|
drop_database
|
drop_table
|
insert
|
optimize_table
|
select
|
show_columns
|
rename_table
|
update
|
use
;

/* === CHECK TABLE === */
check_table:
TOKCHECK TOKTABLE table_ident_commalist
{
   checktable(&gl_query,&gl_result);
}
;

/* === CREATE DATABASE === */
create_database:
TOKCREATE TOKDATABASE if_not_exists IDENT
{
   addIdentElement("",$4,&gl_query);
   createdatabase(&gl_query,&gl_result);
}
;

/* === CREATE TABLE === */
create_table:
TOKCREATE TOKTABLE if_not_exists table_ident PARENTHESEOPEN column_definition_commalist PARENTHESECLOSE
{
   createtable(&gl_query,&gl_result);
}
;

column_definition_commalist:
  column_definition
| column_definition_commalist VIRGULE column_definition
;

column_definition:
  IDENT { AddColumnDefinition($1, &gl_query); } column_type opt_column_options_list
| table_constraint_definition
;

column_type:
TOKTINYINT                             { SetColumnDefinitionType(TYPE_TINYINT, &gl_query); SetColumnDefinitionSize(1, &gl_query) }
| TOKSMALLINT column_type_options      { SetColumnDefinitionType(TYPE_SMALLINT, &gl_query); SetColumnDefinitionSize(1, &gl_query) }
| TOKMEDIUMINT column_type_options     { SetColumnDefinitionType(TYPE_MEDIUMINT, &gl_query); SetColumnDefinitionSize(2, &gl_query) }
| TOKINT column_type_options           { SetColumnDefinitionType(TYPE_INT, &gl_query); SetColumnDefinitionSize(2, &gl_query) }
| TOKINTEGER column_type_options       { SetColumnDefinitionType(TYPE_INTEGER, &gl_query); SetColumnDefinitionSize(2, &gl_query) }
| TOKBIGINT column_type_options        { SetColumnDefinitionType(TYPE_BIGINT, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKREAL column_type_options          { SetColumnDefinitionType(TYPE_REAL, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKDOUBLE column_type_options        { SetColumnDefinitionType(TYPE_DOUBLE, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKFLOAT column_type_options         { SetColumnDefinitionType(TYPE_FLOAT, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKDECIMAL column_type_options       { SetColumnDefinitionType(TYPE_DECIMAL, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKNUMERIC column_type_options       { SetColumnDefinitionType(TYPE_NUMERIC, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKDATE column_type_options          { SetColumnDefinitionType(TYPE_DATE, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKTIME column_type_options          { SetColumnDefinitionType(TYPE_TIME, &gl_query); SetColumnDefinitionSize(3, &gl_query) }
| TOKTIMESTAMP column_type_options     { SetColumnDefinitionType(TYPE_TIMESTAMP, &gl_query); SetColumnDefinitionSize(4, &gl_query) }
| TOKDATETIME column_type_options      { SetColumnDefinitionType(TYPE_DATETIME, &gl_query); SetColumnDefinitionSize(7, &gl_query) }
| TOKCHAR column_type_options          { SetColumnDefinitionType(TYPE_CHAR, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKVARCHAR column_type_options       { SetColumnDefinitionType(TYPE_VARCHAR, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKTINYBLOB column_type_options      { SetColumnDefinitionType(TYPE_TINYBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKBLOB column_type_options          { SetColumnDefinitionType(TYPE_BLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKMEDIUMBLOB column_type_options    { SetColumnDefinitionType(TYPE_MEDIUMBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKLONGBLOB column_type_options      { SetColumnDefinitionType(TYPE_LONGBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKTINYTEXT column_type_options      { SetColumnDefinitionType(TYPE_TINYTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKTEXT column_type_options          { SetColumnDefinitionType(TYPE_TEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKMEDIUMTEXT column_type_options    { SetColumnDefinitionType(TYPE_MEDIUMTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
| TOKLONGTEXT column_type_options      { SetColumnDefinitionType(TYPE_LONGTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) }
;

column_type_options:
/* empty */
| TOKUNSIGNED TOKZEROFILL              { SetColumnDefinitionFlag(FLAG_UNSIGNED | FLAG_ZEROFILL,1,&gl_query); }
| TOKUNSIGNED                          { SetColumnDefinitionFlag(FLAG_UNSIGNED,1,&gl_query); }
| TOKZEROFILL                          { SetColumnDefinitionFlag(FLAG_ZEROFILL,1,&gl_query); }
;


opt_column_options_list:
/* empty */
| opt_column_options_list opt_column_options
;

opt_column_options:
  TOKNULL                                                             { SetColumnDefinitionFlag(FLAG_NULL,1,&gl_query); }
| NOT TOKNULL                                                         { SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); }
| NOT TOKNULL TOKUNIQUE                                               { SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); /* create_index(); */ }
| NOT TOKNULL TOKPRIMARY TOKKEY                                       { SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); /* create_index(); */ }
| TOKDEFAULT atom                                                     { SetColumnDefaultValue($2, &gl_query); FREE_DATA($2);}
| TOKCHECK PARENTHESEOPEN condition PARENTHESECLOSE                   {}
| TOKREFERENCES table_ident                                           {}
| TOKREFERENCES PARENTHESEOPEN table_ident_commalist PARENTHESECLOSE  {}
;

table_constraint_definition:
  TOKUNIQUE PARENTHESEOPEN column_commalist PARENTHESECLOSE
| TOKPRIMARY TOKKEY PARENTHESEOPEN column_commalist PARENTHESECLOSE
| TOKFOREIGN TOKKEY PARENTHESEOPEN column_commalist PARENTHESECLOSE TOKREFERENCES IDENT PARENTHESEOPEN column_commalist PARENTHESECLOSE
| TOKCHECK PARENTHESEOPEN condition PARENTHESECLOSE
;


/* === DELETE === */
deletetbl:
TOKDELETE TOKFROM table_ident_commalist opt_where
{
   deletetbl(&gl_query, &gl_result);
}
;

/* === DROP DATABASE === */
drop_database:
TOKDROP TOKDATABASE if_exists IDENT
{
   addIdentElement("",$4,&gl_query);
   dropdatabase(&gl_query,&gl_result);
}
;

/* === DROP TABLE === */
drop_table:
TOKDROP TOKTABLE if_exists table_ident_commalist
{
   droptable(&gl_query,&gl_result);
}
;


/* === INSERT === */
insert:
TOKINSERT TOKINTO table_ident TOKVALUES PARENTHESEOPEN insert_values_commalist PARENTHESECLOSE
{
   insert(&gl_query, &gl_result);
}
;

insert_values_commalist:
  insert_values
| insert_values_commalist VIRGULE insert_values
;

insert_values:
  atom
    {
        AddData($1, &gl_query);
        gl_query.nbcols++;  
        FREE_DATA($1);
    }  
| TOKNULL
    {
        AddDataVide(&gl_query);
        gl_query.nbcols++;  
    } 
;

/* === OPTIMIZE TABLE === */
optimize_table:
TOKOPTIMIZE TOKTABLE table_ident_commalist
{
   optimizetable(&gl_query, &gl_result);
}
;

/* === RENAME TABLE === */
rename_table:
TOKRENAME TOKTABLE table_rename_table_commalist
{
   renametbl(&gl_query, &gl_result);
}
;

table_rename_table_commalist:
  table_rename_table
| table_rename_table_commalist VIRGULE table_rename_table
;

table_rename_table:
  table_ident TOKTO table_ident
;

/* === SELECT === */
select:
TOKSELECT opt_select_all_distinct select_ident_or_joker TOKFROM table_ident_commalist opt_where
{
  select(&gl_query,&gl_result);
}
;

opt_select_all_distinct:
/* empty */
| TOKALL
| TOKDISTINCT
;

select_ident_or_joker:
select_list_ident
| TIMES {}
;

select_list_ident:
IDENT 
    {
        AddColumnToList(&gl_query,$1,"","");    
    }
| select_list_ident VIRGULE IDENT
    {
        AddColumnToList(&gl_query,$3,"","");    
    }
;

/* === SHOW COLUMNS === */
show_columns:
TOKSHOW TOKCOLUMNS TOKFROM table_ident_commalist
{
    show_columns(&gl_query, &gl_result);
}
;

/* === UPDATE === */
update:
TOKUPDATE table_ident_commalist TOKSET update_values_commalist opt_where
{
update(&gl_query, &gl_result);
}
;
update_values_commalist:
  update_values
| update_values_commalist VIRGULE update_values
;

update_values: /* FIXME: COMPARISON <> EQUAL */
  IDENT COMPARISON scalar_exp {}
| IDENT COMPARISON TOKNULL    {}
;

/* === USE === */
use:
TOKUSE IDENT
{
    addIdentElement("",$2,&gl_query);
    usedb(&gl_query, &gl_result);
}
;

/* === SHARED STATES === */
if_exists:
                { gl_query.if_exists = 0; }
|
TOKIF TOKEXISTS { gl_query.if_exists = 1; }
;

if_not_exists:
/* empty */         { gl_query.if_not_exists = 0; }
|
TOKIF NOT TOKEXISTS { gl_query.if_not_exists = 1; }
;

table_ident_commalist:
| table_ident
| table_ident_commalist VIRGULE table_ident
;

table_ident:
IDENT                   { addIdentElement($1,"",&gl_query); }
| IDENT DOT IDENT       { addIdentElement($3,$1,&gl_query); }
;

column_commalist:
| column
| column_commalist VIRGULE column
;

column:
  IDENT                          {}
| IDENT DOT IDENT                {}
| IDENT DOT IDENT DOT IDENT      {}
;

opt_where:
/* empty */
| TOKWHERE condition { DebugShowWhereResult($2); free_result($2); }
;

condition:
  condition OR condition                         { $$=$1; }
| condition AND condition                        { $$=$1; }
| NOT condition                                  { $$=$2; }
| PARENTHESEOPEN condition PARENTHESECLOSE       { $$=$2; }
| predicate                                      { $$=$1; }
;

predicate:
  comparison_predicate { $$=$1; }
| between_predicate    { $$=$1; }
| like_predicate       { $$=$1; }
| test_for_null        { $$=$1; }
| in_predicate         { $$=$1; }
| existence_test       { $$=$1; }
;

comparison_predicate:
  scalar_exp COMPARISON scalar_exp { filter_comparison(&$$, $1,$3,$2, &gl_query); FREE_DATA($1); FREE_DATA($3); }
| scalar_exp COMPARISON subquery   { /* subquery */ }
;

scalar_exp:
  scalar_exp PLUS scalar_exp                 { AddUnivData($1, $3, &$$);  }
| scalar_exp MINUS scalar_exp                { SubUnivData($1, $3, &$$);  }
| scalar_exp TIMES scalar_exp                { TimesUnivData($1, $3, &$$);}
| scalar_exp DIVIDE scalar_exp               { DivUnivData($1, $3, &$$);  }
| PLUS scalar_exp %prec UMINUS               { $$=$2;                     }
| MINUS scalar_exp %prec UMINUS              { UMinusUnivData($2,&$$);    }
| atom                                       { $$=$1;                     }
| column_ref                                 { $$=$1;                     }
| PARENTHESEOPEN scalar_exp PARENTHESECLOSE  { $$=$2;                     }
;

atom:
  literal { $$=$1; }
;

literal:
  STRING  { $$.data.string=strdup($1); $$.type=CHAINE;   }
| FLOAT   { $$.data.floatNumber=$1;    $$.type=FLOTTANT; }
| INTEGER { $$.data.number=$1;         $$.type=ENTIER;   }
;

column_ref:
  IDENT                     { $$.data.col_ref=strdup($1); $$.type=COLONNE_REF; }
| IDENT DOT IDENT           { $$.data.col_ref=strdup($3); $$.type=COLONNE_REF; }
| IDENT DOT IDENT DOT IDENT { $$.data.col_ref=strdup($5); $$.type=COLONNE_REF; }
;

subquery:
 PARENTHESEOPEN select PARENTHESECLOSE { /* jointure nécessaires */ }
;

between_predicate:
  scalar_exp NOT TOKBETWEEN scalar_exp AND scalar_exp { /* filter_between() */ }
| scalar_exp TOKBETWEEN scalar_exp AND scalar_exp     { /* filter_not_between() */ }
;

like_predicate:
  scalar_exp NOT TOKLIKE atom      { /* filter_not_like() */ }
| scalar_exp TOKLIKE atom          { /* filter_like() */ }
;

test_for_null:
  column_ref TOKIS NOT TOKNULL     { /* filter_is_not_null() */ }
| column_ref TOKIS TOKNULL         { /* filter_is_null() */ }
;

in_predicate:
  scalar_exp NOT TOKIN PARENTHESEOPEN subquery PARENTHESECLOSE       { /* subquery */ }
| scalar_exp TOKIN PARENTHESEOPEN subquery PARENTHESECLOSE           { /* subquery */ }
| scalar_exp NOT TOKIN PARENTHESEOPEN atom_commalist PARENTHESECLOSE { /* filter_not_in()*/ }
| scalar_exp TOKIN PARENTHESEOPEN atom_commalist PARENTHESECLOSE     { /* filter_in()*/ }
;

atom_commalist:
  atom                            {}
| atom_commalist VIRGULE atom     {}

existence_test:
  TOKEXISTS subquery              { /* subquery */ }

%%
