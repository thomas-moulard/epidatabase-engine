%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"
#include "sql_tab.h"

extern char *strdup(const char*);
extern int fileno();

extern YYSTYPE yylval;
%}

%%

'[^'\n]*' {
             int c = input();
		       unput(c);	/* just peeking */
		       if(c != '\'')
		       {
                yylval.string=(char*)strdup(yytext);
                unquote_string(yylval.string);
			       return STRING;
	           } else
			        yymore();
          }

ADD			    return TOKADD;
ALL			    return TOKALL;
ALTER			return TOKALTER;
ANALYZE			return TOKANALYSE;
AND			    return AND;
AS			    return TOKAS;
ASC			    return TOKASC;
ASENSITIVE		return TOKASENSITIVE;
BEFORE			return TOKBEFORE;
BETWEEN			return TOKBETWEEN;
BIGINT			return TOKBIGINT;
BINARY			return TOKBINARY;
BLOB			return TOKBLOB;
BOTH			return TOKBOTH;
BY			    return TOKBY;
CALL			return TOKCALL;
CASCADE			return TOKCASCADE;
CASE			return TOKCASE;
CHANGE			return TOKCHANGE;
CHAR			return TOKCHAR;
CHARACTER		return TOKCHARACTER;
CHECK			return TOKCHECK;
COLLATE			return TOKCOLLATE;
COLUMN			return TOKCOLUMN;
COLUMNS			return TOKCOLUMNS;
CONDITION		return TOKCONDITION;
CONNECTION		return TOKCONNECTION;
CONSTRAINT		return TOKCONSTRAINT;
CONTINUE		return TOKCONTINUE;
CONVERT			return TOKCONVERT;
CREATE			return TOKCREATE;
CROSS			return TOKCROSS;
CURRENT_DATE		return TOKCURRENT_DATE;
CURRENT_TIME		return TOKCURRENT_TIME;
CURRENT_TIMESTAMP	return TOKCURRENT_TIMESTAMP;
CURRENT_USER		return TOKCURRENT_USER;
CURSOR			return TOKCURSOR;
DATABASE		return TOKDATABASE;
DATABASES		return TOKDATABASES;
DAY_HOUR		return TOKDAY_HOUR;
DAY_MICROSECOND		return TOKDAY_MICROSECOND;
DAY_MINUTE		return TOKDAY_MINUTE;
DAY_SECOND		return TOKDAY_SECOND;
DEC			    return TOKDEC;
DECIMAL			return TOKDECIMAL;
DECLARE			return TOKDECLARE;
DEFAULT			return TOKDEFAULT;
DELAYED			return TOKDELAYED;
DELETE			return TOKDELETE;
DESC			return TOKDESC;
DESCRIBE		return TOKDESCRIBE;
DETERMINISTIC		return TOKDETERMINISTIC;
DISTINCT		return TOKDISTINCT;
DISTINCTROW		return TOKDISTINCTROW;
DIV			    return TOKDIV;
DOUBLE			return TOKDOUBLE;
DROP			return TOKDROP;
DUAL			return TOKDUAL;
EACH			return TOKEACH;
ELSE			return TOKELSE;
ELSEIF			return TOKELSEIF;
ENCLOSED		return TOKENCLOSED;
ESCAPED			return TOKESCAPED;
EXISTS			return TOKEXISTS;
EXIT			return TOKEXIT;
EXPLAIN			return TOKEXPLAIN;
FALSE			return TOKFALSE;
FETCH			return TOKFETCH;
FLOAT			return TOKFLOAT;
FOR			    return TOKFOR;
FORCE			return TOKFORCE;
FOREIGN			return TOKFOREIGN;
FROM			return TOKFROM;
FULLTEXT		return TOKFULLTEXT;
GOTO			return TOKGOTO;
GRANT			return TOKGRANT;
GROUP			return TOKGROUP;
HAVING			return TOKHAVING;
HIGH_PRIORITY		return TOKHIGH_PRIORITY;
HOUR_MICROSECOND	return TOKHOUR_MICROSECOND;
HOUR_MINUTE		return TOKHOUR_MINUTE;
HOUR_SECOND		return TOKHOUR_SECOND;
IF			    return TOKIF;
IGNORE			return TOKIGNORE;
IN			    return TOKIN;
INDEX			return TOKINDEX;
INFILE			return TOKINFILE;
INNER			return TOKINNER;
INOUT			return TOKINOUT;
INSENSITIVE		return TOKINSENSITIVE;
INSERT			return TOKINSERT;
INT			    return TOKINT;
INTEGER			return TOKINTEGER;
INTERVAL		return TOKINTERVAL;
INTO			return TOKINTO;
IS			    return TOKIS;
ITERATE			return TOKITERATE;
JOIN			return TOKJOIN;
KEY			    return TOKKEY;
KEYS			return TOKKEYS;
KILL			return TOKKILL;
LEADING			return TOKLEADING;
LEAVE			return TOKLEAVE;
LEFT			return TOKLEFT;
LIKE			return TOKLIKE;
LIMIT			return TOKLIMIT;
LINES			return TOKLINES;
LOAD			return TOKLOAD;
LOCALTIME		return TOKLOCALTIME;
LOCALTIMESTAMP		return TOKLOCALTIMESTAMP;
LOCK			return TOKLOCK;
LONG			return TOKLONG;
LONGBLOB		return TOKLONGBLOB;
LONGTEXT		return TOKLONGTEXT;
LOOP			return TOKLOOP;
LOW_PRIORITY		return TOKLOW_PRIORITY;
MATCH			return TOKMATCH;
MEDIUMBLOB		return TOKMEDIUMBLOB;
MEDIUMINT		return TOKMEDIUMINT;
MEDIUMTEXT		return TOKMEDIUMTEXT;
MIDDLEINT		return TOKMIDDLEINT;
MINUTE_MICROSECOND	return TOKMINUTE_MICROSECOND;
MINUTE_SECOND		return TOKMINUTE_SECOND;
MOD			    return TOKMOD;
MODIFIES		return TOKMODIFIES;
NATURAL			return TOKNATURAL;
NOT			    return NOT;
NO_WRITE_TO_BINLOG	return TOKNO_WRITE_TO_BINLOG;
NULL			return TOKNULL;
NUMERIC			return TOKNUMERIC;
ON			    return TOKON;
OPTIMIZE		return TOKOPTIMIZE;
OPTION			return TOKOPTION;
OPTIONALLY		return TOKOPTIONALLY;
OR			    return OR;
ORDER			return TOKORDER;
OUT			    return TOKOUT;
OUTER			return TOKOUTER;
OUTFILE			return TOKOUTFILE;
PRECISION		return TOKPRECISION;
PRIMARY			return TOKPRIMARY;
PROCEDURE		return TOKPROCEDURE;
PURGE			return TOKPURGE;
READ			return TOKREAD;
READS			return TOKREADS;
REAL			return TOKREAL;
REFERENCES		return TOKREFERENCES;
REGEXP			return TOKREGEXP;
RENAME			return TOKRENAME;
REPEAT			return TOKREPEAT;
REPLACE			return TOKREPLACE;
REQUIRE			return TOKREQUIRE;
RESTRICT		return TOKRESTRICT;
RETURN			return TOKRETURN;
REVOKE			return TOKREVOKE;
RIGHT			return TOKRIGHT;
RLIKE			return TOKRLIKE;
SCHEMA			return TOKSCHEMA;
SCHEMAS			return TOKSCHEMAS;
SECOND_MICROSECOND	return TOKSECOND_MICROSECOND;
SELECT			return TOKSELECT;
SENSITIVE		return TOKSENSITIVE;
SEPARATOR		return TOKSEPARATOR;
SET			    return TOKSET;
SHOW			return TOKSHOW;
SMALLINT		return TOKSMALLINT;
SONAME			return TOKSONAME;
SPATIAL			return TOKSPATIAL;
SPECIFIC		return TOKSPECIFIC;
SQL			    return TOKSQL;
SQLEXCEPTION    return TOKSQLEXCEPTION;
SQLSTATE		return TOKSQLSTATE;
SQLWARNING		return TOKSQLWARNING;
SQL_BIG_RESULT		return TOKSQL_BIG_RESULT;
SQL_CALC_FOUND_ROWS	return TOKSQL_CALC_FOUND_ROWS;
SQL_SMALL_RESULT	return TOKSQL_SMALL_RESULT;
SSL			    return TOKSSL;
STARTING		return TOKSTARTING;
STRAIGHT_JOIN   return TOKSTRAIGHT_JOIN;
TABLE			return TOKTABLE;
TABLES			return TOKTABLES;
TERMINATED		return TOKTERMINATED;
THEN			return TOKTHEN;
TINYBLOB		return TOKTINYBLOB;
TINYINT			return TOKTINYINT;
TINYTEXT		return TOKTINYTEXT;
TO			    return TOKTO;
TRAILING		return TOKTRAILING;
TRIGGER			return TOKTRIGGER;
TRUE			return TOKTRUE;
UNDO			return TOKUNDO;
UNION			return TOKUNION;
UNIQUE			return TOKUNIQUE;
UNLOCK			return TOKUNLOCK;
UNSIGNED		return TOKUNSIGNED;
UPDATE			return TOKUPDATE;
USAGE			return TOKUSAGE;
USE			    return TOKUSE;
USING			return TOKUSING;
UTC_DATE		return TOKUTC_DATE;
UTC_TIME		return TOKUTC_TIME;
UTC_TIMESTAMP	return TOKUTC_TIMESTAMP;
VALUES			return TOKVALUES;
VARBINARY		return TOKVARBINARY;
VARCHAR			return TOKVARCHAR;
VARCHARACTER	return TOKVARCHARACTER;
VARYING			return TOKVARYING;
WHEN			return TOKWHEN;
WHERE			return TOKWHERE;
WHILE			return TOKWHILE;
WITH			return TOKWITH;
WRITE			return TOKWRITE;
XOR			    return TOKXOR;
YEAR_MONTH		return TOKYEAR_MONTH;
ZEROFILL		return TOKZEROFILL;

\.			            return DOT;
;			            return SEMICOLON;
,			            return VIRGULE;
\(			            return PARENTHESEOPEN;
\)			            return PARENTHESECLOSE;

\+                   return PLUS;
\-                   return MINUS;
\*                   return TIMES;
\/                   return DIVIDE;

\<=                  yylval.subtok=LEQ; return COMPARISON;
\>=                  yylval.subtok=GEQ; return COMPARISON;
\<\>                 yylval.subtok=NEQUAL; return COMPARISON;
\<                   yylval.subtok=LESS; return COMPARISON;
\>                   yylval.subtok=GREAT; return COMPARISON;
=                    yylval.subtok=EQUAL; return COMPARISON;

[0-9]+\.[0-9]*	      yylval.floatNumber=atof(yytext); return FLOAT;
[0-9]+			      yylval.number=atoi(yytext); return INTEGER;

[a-zA-Z0-9]{1,255}	yylval.string=(char*)strdup(yytext); return IDENT;
`[a-zA-Z0-9]{1,255}` yylval.string=(char*)strdup(yytext); unquote(yylval.string); return IDENT;

"--".*               /* comment */

\n		               /* ignore end of line */;
[ \t]+		         /* ignore whitespace */;
.			            /* ignore */
%%
