/*
** types.h for epiDatabase
**
** Made by Julien Assémat
** Login   moular_t
**
** Started on  01/01/2005 assema_j
** Last update 25/02/2005 moular_t
*/

#ifndef TYPES_H_
# define TYPES_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** Types for strings
*/
# define S_DATABASE 64
# define S_TABLE    64
# define S_COLUMN   64
# define S_INDEX    64
# define S_ALIAS    256
/*
** Comparisons
*/
# define EQUAL     0 /* = */
# define GREAT     1 /* > */
# define LESS      2 /* < */
# define GEQ       3 /* >= */
# define LEQ       4 /* <= */
# define NEQUAL    5 /* <> */


typedef enum { VIDE = 0, FLOTTANT, ENTIER, CHAINE, COLONNE_REF } e_basic_type;
union u_data
{
   double            floatNumber;
   int               number;
   char              * string;
   char              * col_ref; /* ONLY USED IN SCALAR, NOT ATOM ! */
};

struct s_univdata
{
   union u_data data;
   e_basic_type type;
};

typedef char              t_dbname[S_DATABASE-1];
typedef char              t_tblname[S_TABLE-1];
typedef char              t_columnname[S_COLUMN-1];
typedef char              t_indexname[S_INDEX-1];
typedef char              t_aliasname[S_ALIAS-1];

/* Pointer */  
typedef struct s_table          *p_table;
typedef struct s_lident         *p_lident;
typedef struct s_ldata          *p_ldata;
typedef struct s_lfield         *p_lfield;
typedef struct s_lrow           *p_lrow;

struct                    s_lident
{
   t_tblname              tbl_name;
   t_dbname               db_name;
   p_lident               next;
};

struct                    s_lfield
{
   t_tblname              tbl_name;
   t_dbname               db_name;
   t_columnname           field_name;
   p_lfield               next;
};

struct                    s_ldata
{
   struct s_univdata      data;
   p_ldata                next;
};

struct                    s_sql_query
{
   p_lident               identlist;
   p_lfield               fieldlist;
   p_ldata                datalist;
   t_dbname               default_dbname; /* if no db name is specified, use this */
   
   p_table                table;
   int                    nbcols;
   
   int                    if_exists;
   int                    if_not_exists;
};

/*
** List of result
*/
struct                    s_lrow
{
   unsigned int           row_id; /* address in data file = row_id*size_of_row */
   p_lrow                 next;
};


/*
** error_code: 0 => success / !0 => error
*/
struct                    s_sql_result
{
   int                    error_code;
};

/*
** Type of columns
*/
# define TYPE_TINYINT       1
# define TYPE_SMALLINT      2
# define TYPE_MEDIUMINT     3
# define TYPE_INT           4
# define TYPE_INTEGER       5
# define TYPE_BIGINT        7
# define TYPE_REAL          8
# define TYPE_DOUBLE        9
# define TYPE_FLOAT         10
# define TYPE_DECIMAL       11
# define TYPE_NUMERIC       12
# define TYPE_DATE          13
# define TYPE_TIME          14
# define TYPE_TIMESTAMP     15
# define TYPE_DATETIME      16
# define TYPE_CHAR          17
# define TYPE_VARCHAR       18
# define TYPE_TINYBLOB      19
# define TYPE_BLOB          20
# define TYPE_MEDIUMBLOB    21
# define TYPE_LONGBLOB      22
# define TYPE_TINYTEXT      23
# define TYPE_TEXT          24
# define TYPE_MEDIUMTEXT    25
# define TYPE_LONGTEXT      26

/*
** flags: | NOT USED | UNSIGNED | ZEROFILL | BINARY | ASCII | UNICODE | NULL |
**
*/
# define FLAG_NULL     1  /* bit 1 */
# define FLAG_UNICODE  2  /* bit 2 */
# define FLAG_ASCII    4  /* bit 3 */
# define FLAG_BINARY   16 /* bit 4 */
# define FLAG_ZEROFILL 32 /* bit 5 */
# define FLAG_UNSIGNED 64 /* bit 6 */
/*                           NOT USED - bit 7 */

struct                    s_column
{
   t_columnname           name;
   unsigned char          type;
   unsigned char          size;
   char                   flags;   
   struct s_univdata      def_value;
};


struct                    s_table
{
   struct s_column        column;
   p_table                next;
};


void unquote(char * str);
void unquote_string(char * str);
void init_sql_query(struct s_sql_query *query);
void init_sql_result(struct s_sql_result *result);
void init_insert_data(p_ldata * data);
void init_p_table(p_table * table);
void reinit_sql_query(struct s_sql_query *query);
void reinit_sql_result(struct s_sql_result *result);

/* IdentList */
void addIdentElement(t_tblname tblname, t_dbname dbname, struct s_sql_query *query);
char * getFirstTblName(struct s_sql_query *query);
char * getFirstDbName(struct s_sql_query *query);

void DebugShowIdentList(struct s_sql_query *query);
void DebugShowTable(struct s_sql_query *query);

void AddUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res);
void SubUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res);
void UMinusUnivData(struct s_univdata l, struct s_univdata *res);
void TimesUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res);
void DivUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res);

#endif /* !TYPES_H_ */
