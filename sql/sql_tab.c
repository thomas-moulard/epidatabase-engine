
/*  A Bison parser, made from sql.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TOKADD	258
#define	TOKALL	259
#define	TOKALTER	260
#define	TOKANALYSE	261
#define	TOKAS	262
#define	TOKASC	263
#define	TOKASENSITIVE	264
#define	TOKBEFORE	265
#define	TOKBETWEEN	266
#define	TOKBIGINT	267
#define	TOKBINARY	268
#define	TOKBLOB	269
#define	TOKBOTH	270
#define	TOKBINARYTOKBLOB	271
#define	TOKBY	272
#define	TOKCALL	273
#define	TOKCASCADE	274
#define	TOKCASE	275
#define	TOKCHANGE	276
#define	TOKCHAR	277
#define	TOKCHARACTER	278
#define	TOKCHECK	279
#define	TOKCOLLATE	280
#define	TOKCOLUMN	281
#define	TOKCOLUMNS	282
#define	TOKCONDITION	283
#define	TOKCONNECTION	284
#define	TOKCONSTRAINT	285
#define	TOKCONTINUE	286
#define	TOKCONVERT	287
#define	TOKCREATE	288
#define	TOKCROSS	289
#define	TOKCURRENT_DATE	290
#define	TOKCURRENT_TIME	291
#define	TOKCURRENT_TIMESTAMP	292
#define	TOKCURRENT_USER	293
#define	TOKCURSOR	294
#define	TOKDATABASE	295
#define	TOKDATABASES	296
#define	TOKDATE	297
#define	TOKDATETIME	298
#define	TOKDAY_HOUR	299
#define	TOKDAY_MICROSECOND	300
#define	TOKDAY_MINUTE	301
#define	TOKDAY_SECOND	302
#define	TOKDEC	303
#define	TOKDECIMAL	304
#define	TOKDECLARE	305
#define	TOKDEFAULT	306
#define	TOKDELAYED	307
#define	TOKDELETE	308
#define	TOKDESC	309
#define	TOKDESCRIBE	310
#define	TOKDETERMINISTIC	311
#define	TOKDISTINCT	312
#define	TOKDISTINCTROW	313
#define	TOKDIV	314
#define	TOKDOUBLE	315
#define	TOKDROP	316
#define	TOKDUAL	317
#define	TOKEACH	318
#define	TOKELSE	319
#define	TOKELSEIF	320
#define	TOKENCLOSED	321
#define	TOKESCAPED	322
#define	TOKEXISTS	323
#define	TOKEXIT	324
#define	TOKEXPLAIN	325
#define	TOKFALSE	326
#define	TOKFETCH	327
#define	TOKFLOAT	328
#define	TOKFOR	329
#define	TOKFORCE	330
#define	TOKFOREIGN	331
#define	TOKFROM	332
#define	TOKFULLTEXT	333
#define	TOKGOTO	334
#define	TOKGRANT	335
#define	TOKGROUP	336
#define	TOKHAVING	337
#define	TOKHIGH_PRIORITY	338
#define	TOKHOUR_MICROSECOND	339
#define	TOKHOUR_MINUTE	340
#define	TOKHOUR_SECOND	341
#define	TOKIF	342
#define	TOKIGNORE	343
#define	TOKIN	344
#define	TOKINDEX	345
#define	TOKINFILE	346
#define	TOKINNER	347
#define	TOKINOUT	348
#define	TOKINSENSITIVE	349
#define	TOKINSERT	350
#define	TOKINT	351
#define	TOKINTEGER	352
#define	TOKINTERVAL	353
#define	TOKINTO	354
#define	TOKIS	355
#define	TOKITERATE	356
#define	TOKJOIN	357
#define	TOKKEY	358
#define	TOKKEYS	359
#define	TOKKILL	360
#define	TOKLEADING	361
#define	TOKLEAVE	362
#define	TOKLEFT	363
#define	TOKLIKE	364
#define	TOKLIMIT	365
#define	TOKLINES	366
#define	TOKLOAD	367
#define	TOKLOCALTIME	368
#define	TOKLOCALTIMESTAMP	369
#define	TOKLOCK	370
#define	TOKLONG	371
#define	TOKLONGBLOB	372
#define	TOKLONGTEXT	373
#define	TOKLOOP	374
#define	TOKLOW_PRIORITY	375
#define	TOKMATCH	376
#define	TOKMEDIUMBLOB	377
#define	TOKMEDIUMINT	378
#define	TOKMEDIUMTEXT	379
#define	TOKMIDDLEINT	380
#define	TOKMINUTE_MICROSECOND	381
#define	TOKMINUTE_SECOND	382
#define	TOKMOD	383
#define	TOKMODIFIES	384
#define	TOKNATURAL	385
#define	TOKNO_WRITE_TO_BINLOG	386
#define	TOKNULL	387
#define	TOKNUMERIC	388
#define	TOKON	389
#define	TOKOPTIMIZE	390
#define	TOKOPTION	391
#define	TOKOPTIONALLY	392
#define	TOKORDER	393
#define	TOKOUT	394
#define	TOKOUTER	395
#define	TOKOUTFILE	396
#define	TOKPRECISION	397
#define	TOKPRIMARY	398
#define	TOKPROCEDURE	399
#define	TOKPURGE	400
#define	TOKREAD	401
#define	TOKREADS	402
#define	TOKREAL	403
#define	TOKREFERENCES	404
#define	TOKREGEXP	405
#define	TOKRENAME	406
#define	TOKREPEAT	407
#define	TOKREPLACE	408
#define	TOKREQUIRE	409
#define	TOKRESTRICT	410
#define	TOKRETURN	411
#define	TOKREVOKE	412
#define	TOKRIGHT	413
#define	TOKRLIKE	414
#define	TOKSCHEMA	415
#define	TOKSCHEMAS	416
#define	TOKSECOND_MICROSECOND	417
#define	TOKSELECT	418
#define	TOKSENSITIVE	419
#define	TOKSEPARATOR	420
#define	TOKSET	421
#define	TOKSHOW	422
#define	TOKSMALLINT	423
#define	TOKSONAME	424
#define	TOKSPATIAL	425
#define	TOKSPECIFIC	426
#define	TOKSQL	427
#define	TOKSQLEXCEPTION	428
#define	TOKSQLSTATE	429
#define	TOKSQLWARNING	430
#define	TOKSQL_BIG_RESULT	431
#define	TOKSQL_CALC_FOUND_ROWS	432
#define	TOKSQL_SMALL_RESULT	433
#define	TOKSSL	434
#define	TOKSTARTING	435
#define	TOKSTRAIGHT_JOIN	436
#define	TOKTABLE	437
#define	TOKTABLES	438
#define	TOKTERMINATED	439
#define	TOKTEXT	440
#define	TOKTHEN	441
#define	TOKTIME	442
#define	TOKTIMESTAMP	443
#define	TOKTINYBLOB	444
#define	TOKTINYINT	445
#define	TOKTINYTEXT	446
#define	TOKTO	447
#define	TOKTRAILING	448
#define	TOKTRIGGER	449
#define	TOKTRUE	450
#define	TOKUNDO	451
#define	TOKUNION	452
#define	TOKUNIQUE	453
#define	TOKUNLOCK	454
#define	TOKUNSIGNED	455
#define	TOKUPDATE	456
#define	TOKUSAGE	457
#define	TOKUSE	458
#define	TOKUSING	459
#define	TOKUTC_DATE	460
#define	TOKUTC_TIME	461
#define	TOKUTC_TIMESTAMP	462
#define	TOKVALUES	463
#define	TOKVARBINARY	464
#define	TOKVARCHAR	465
#define	TOKVARCHARACTER	466
#define	TOKVARYING	467
#define	TOKWHEN	468
#define	TOKWHERE	469
#define	TOKWHILE	470
#define	TOKWITH	471
#define	TOKWRITE	472
#define	TOKXOR	473
#define	TOKYEAR_MONTH	474
#define	TOKZEROFILL	475
#define	DOT	476
#define	SEMICOLON	477
#define	STRING	478
#define	FLOAT	479
#define	INTEGER	480
#define	IDENT	481
#define	VIRGULE	482
#define	PARENTHESEOPEN	483
#define	PARENTHESECLOSE	484
#define	OR	485
#define	AND	486
#define	NOT	487
#define	PLUS	488
#define	MINUS	489
#define	TIMES	490
#define	DIVIDE	491
#define	UMINUS	492
#define	COMPARISON	493

#line 1 "sql.y"


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


#line 94 "sql.y"
typedef union
{
double floatNumber;
int number;
char *string;
char subtok;

struct s_univdata data;
p_lrow where_clause;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		310
#define	YYFLAG		-32768
#define	YYNTBASE	239

#define YYTRANSLATE(x) ((unsigned)(x) <= 493 ? yytranslate[x] : 295)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
   196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
   216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
   226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
   236,   237,   238
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     5,     6,    11,    12,    14,    16,    18,    20,
    22,    24,    26,    28,    30,    32,    34,    36,    38,    40,
    44,    49,    57,    59,    63,    64,    69,    71,    73,    76,
    79,    82,    85,    88,    91,    94,    97,   100,   103,   106,
   109,   112,   115,   118,   121,   124,   127,   130,   133,   136,
   139,   142,   145,   146,   149,   151,   153,   154,   157,   159,
   162,   166,   171,   174,   179,   182,   187,   192,   198,   209,
   214,   219,   224,   229,   237,   239,   243,   245,   247,   251,
   255,   257,   261,   265,   272,   273,   275,   277,   279,   281,
   283,   287,   292,   298,   300,   304,   308,   312,   315,   316,
   319,   320,   324,   325,   327,   331,   333,   337,   338,   340,
   344,   346,   350,   356,   357,   360,   364,   368,   371,   375,
   377,   379,   381,   383,   385,   387,   389,   393,   397,   401,
   405,   409,   413,   416,   419,   421,   423,   427,   429,   431,
   433,   435,   437,   441,   447,   451,   458,   464,   469,   473,
   478,   482,   489,   495,   502,   508,   510,   514
};

static const short yyrhs[] = {    -1,
   243,   240,   222,     0,     0,   239,   243,   241,   242,     0,
     0,   222,     0,   244,     0,   245,     0,   246,     0,   255,
     0,   256,     0,   257,     0,   258,     0,   261,     0,   265,
     0,   269,     0,   262,     0,   270,     0,   273,     0,    24,
   182,   276,     0,    33,    40,   275,   226,     0,    33,   182,
   275,   277,   228,   247,   229,     0,   248,     0,   247,   227,
   248,     0,     0,   226,   249,   250,   252,     0,   254,     0,
   190,     0,   168,   251,     0,   123,   251,     0,    96,   251,
     0,    97,   251,     0,    12,   251,     0,   148,   251,     0,
    60,   251,     0,    73,   251,     0,    49,   251,     0,   133,
   251,     0,    42,   251,     0,   187,   251,     0,   188,   251,
     0,    43,   251,     0,    22,   251,     0,   210,   251,     0,
   189,   251,     0,    14,   251,     0,   122,   251,     0,   117,
   251,     0,   191,   251,     0,   185,   251,     0,   124,   251,
     0,   118,   251,     0,     0,   200,   220,     0,   200,     0,
   220,     0,     0,   252,   253,     0,   132,     0,   232,   132,
     0,   232,   132,   198,     0,   232,   132,   143,   103,     0,
    51,   285,     0,    24,   228,   281,   229,     0,   149,   277,
     0,   149,   228,   276,   229,     0,   198,   228,   278,   229,
     0,   143,   103,   228,   278,   229,     0,    76,   103,   228,
   278,   229,   149,   226,   228,   278,   229,     0,    24,   228,
   281,   229,     0,    53,    77,   276,   280,     0,    61,    40,
   274,   226,     0,    61,   182,   274,   276,     0,    95,    99,
   277,   208,   228,   259,   229,     0,   260,     0,   259,   227,
   260,     0,   285,     0,   132,     0,   135,   182,   276,     0,
   151,   182,   263,     0,   264,     0,   263,   227,   264,     0,
   277,   192,   277,     0,   163,   266,   267,    77,   276,   280,
     0,     0,     4,     0,    57,     0,   268,     0,   235,     0,
   226,     0,   268,   227,   226,     0,   167,    27,    77,   276,
     0,   201,   276,   166,   271,   280,     0,   272,     0,   271,
   227,   272,     0,   226,   238,   284,     0,   226,   238,   132,
     0,   203,   226,     0,     0,    87,    68,     0,     0,    87,
   232,    68,     0,     0,   277,     0,   276,   227,   277,     0,
   226,     0,   226,   221,   226,     0,     0,   279,     0,   278,
   227,   279,     0,   226,     0,   226,   221,   226,     0,   226,
   221,   226,   221,   226,     0,     0,   214,   281,     0,   281,
   230,   281,     0,   281,   231,   281,     0,   232,   281,     0,
   228,   281,   229,     0,   282,     0,   283,     0,   289,     0,
   290,     0,   291,     0,   292,     0,   294,     0,   284,   238,
   284,     0,   284,   238,   288,     0,   284,   233,   284,     0,
   284,   234,   284,     0,   284,   235,   284,     0,   284,   236,
   284,     0,   233,   284,     0,   234,   284,     0,   285,     0,
   287,     0,   228,   284,   229,     0,   286,     0,   223,     0,
   224,     0,   225,     0,   226,     0,   226,   221,   226,     0,
   226,   221,   226,   221,   226,     0,   228,   265,   229,     0,
   284,   232,    11,   284,   231,   284,     0,   284,    11,   284,
   231,   284,     0,   284,   232,   109,   285,     0,   284,   109,
   285,     0,   287,   100,   232,   132,     0,   287,   100,   132,
     0,   284,   232,    89,   228,   288,   229,     0,   284,    89,
   228,   288,   229,     0,   284,   232,    89,   228,   293,   229,
     0,   284,    89,   228,   293,   229,     0,   285,     0,   293,
   227,   285,     0,    68,   288,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   124,   126,   126,   127,   129,   131,   134,   136,   138,   140,
   142,   144,   146,   148,   150,   152,   154,   156,   158,   163,
   171,   180,   187,   189,   192,   193,   194,   197,   199,   200,
   201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
   211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   225,   227,   228,   229,   233,   235,   238,   240,
   241,   242,   243,   244,   245,   246,   249,   251,   252,   253,
   258,   266,   275,   284,   291,   293,   296,   303,   311,   319,
   326,   328,   331,   336,   343,   345,   346,   349,   351,   354,
   359,   366,   374,   380,   382,   385,   387,   391,   400,   402,
   406,   408,   412,   413,   414,   417,   419,   422,   423,   424,
   427,   429,   430,   433,   435,   438,   440,   441,   442,   443,
   446,   448,   449,   450,   451,   452,   455,   457,   460,   462,
   463,   464,   465,   466,   467,   468,   469,   472,   476,   478,
   479,   482,   484,   485,   488,   492,   494,   497,   499,   502,
   504,   507,   509,   510,   511,   514,   516,   518
};

static const char * const yytname[] = {   "$","error","$undefined.","TOKADD",
"TOKALL","TOKALTER","TOKANALYSE","TOKAS","TOKASC","TOKASENSITIVE","TOKBEFORE",
"TOKBETWEEN","TOKBIGINT","TOKBINARY","TOKBLOB","TOKBOTH","TOKBINARYTOKBLOB",
"TOKBY","TOKCALL","TOKCASCADE","TOKCASE","TOKCHANGE","TOKCHAR","TOKCHARACTER",
"TOKCHECK","TOKCOLLATE","TOKCOLUMN","TOKCOLUMNS","TOKCONDITION","TOKCONNECTION",
"TOKCONSTRAINT","TOKCONTINUE","TOKCONVERT","TOKCREATE","TOKCROSS","TOKCURRENT_DATE",
"TOKCURRENT_TIME","TOKCURRENT_TIMESTAMP","TOKCURRENT_USER","TOKCURSOR","TOKDATABASE",
"TOKDATABASES","TOKDATE","TOKDATETIME","TOKDAY_HOUR","TOKDAY_MICROSECOND","TOKDAY_MINUTE",
"TOKDAY_SECOND","TOKDEC","TOKDECIMAL","TOKDECLARE","TOKDEFAULT","TOKDELAYED",
"TOKDELETE","TOKDESC","TOKDESCRIBE","TOKDETERMINISTIC","TOKDISTINCT","TOKDISTINCTROW",
"TOKDIV","TOKDOUBLE","TOKDROP","TOKDUAL","TOKEACH","TOKELSE","TOKELSEIF","TOKENCLOSED",
"TOKESCAPED","TOKEXISTS","TOKEXIT","TOKEXPLAIN","TOKFALSE","TOKFETCH","TOKFLOAT",
"TOKFOR","TOKFORCE","TOKFOREIGN","TOKFROM","TOKFULLTEXT","TOKGOTO","TOKGRANT",
"TOKGROUP","TOKHAVING","TOKHIGH_PRIORITY","TOKHOUR_MICROSECOND","TOKHOUR_MINUTE",
"TOKHOUR_SECOND","TOKIF","TOKIGNORE","TOKIN","TOKINDEX","TOKINFILE","TOKINNER",
"TOKINOUT","TOKINSENSITIVE","TOKINSERT","TOKINT","TOKINTEGER","TOKINTERVAL",
"TOKINTO","TOKIS","TOKITERATE","TOKJOIN","TOKKEY","TOKKEYS","TOKKILL","TOKLEADING",
"TOKLEAVE","TOKLEFT","TOKLIKE","TOKLIMIT","TOKLINES","TOKLOAD","TOKLOCALTIME",
"TOKLOCALTIMESTAMP","TOKLOCK","TOKLONG","TOKLONGBLOB","TOKLONGTEXT","TOKLOOP",
"TOKLOW_PRIORITY","TOKMATCH","TOKMEDIUMBLOB","TOKMEDIUMINT","TOKMEDIUMTEXT",
"TOKMIDDLEINT","TOKMINUTE_MICROSECOND","TOKMINUTE_SECOND","TOKMOD","TOKMODIFIES",
"TOKNATURAL","TOKNO_WRITE_TO_BINLOG","TOKNULL","TOKNUMERIC","TOKON","TOKOPTIMIZE",
"TOKOPTION","TOKOPTIONALLY","TOKORDER","TOKOUT","TOKOUTER","TOKOUTFILE","TOKPRECISION",
"TOKPRIMARY","TOKPROCEDURE","TOKPURGE","TOKREAD","TOKREADS","TOKREAL","TOKREFERENCES",
"TOKREGEXP","TOKRENAME","TOKREPEAT","TOKREPLACE","TOKREQUIRE","TOKRESTRICT",
"TOKRETURN","TOKREVOKE","TOKRIGHT","TOKRLIKE","TOKSCHEMA","TOKSCHEMAS","TOKSECOND_MICROSECOND",
"TOKSELECT","TOKSENSITIVE","TOKSEPARATOR","TOKSET","TOKSHOW","TOKSMALLINT","TOKSONAME",
"TOKSPATIAL","TOKSPECIFIC","TOKSQL","TOKSQLEXCEPTION","TOKSQLSTATE","TOKSQLWARNING",
"TOKSQL_BIG_RESULT","TOKSQL_CALC_FOUND_ROWS","TOKSQL_SMALL_RESULT","TOKSSL",
"TOKSTARTING","TOKSTRAIGHT_JOIN","TOKTABLE","TOKTABLES","TOKTERMINATED","TOKTEXT",
"TOKTHEN","TOKTIME","TOKTIMESTAMP","TOKTINYBLOB","TOKTINYINT","TOKTINYTEXT",
"TOKTO","TOKTRAILING","TOKTRIGGER","TOKTRUE","TOKUNDO","TOKUNION","TOKUNIQUE",
"TOKUNLOCK","TOKUNSIGNED","TOKUPDATE","TOKUSAGE","TOKUSE","TOKUSING","TOKUTC_DATE",
"TOKUTC_TIME","TOKUTC_TIMESTAMP","TOKVALUES","TOKVARBINARY","TOKVARCHAR","TOKVARCHARACTER",
"TOKVARYING","TOKWHEN","TOKWHERE","TOKWHILE","TOKWITH","TOKWRITE","TOKXOR","TOKYEAR_MONTH",
"TOKZEROFILL","DOT","SEMICOLON","STRING","FLOAT","INTEGER","IDENT","VIRGULE",
"PARENTHESEOPEN","PARENTHESECLOSE","OR","AND","NOT","PLUS","MINUS","TIMES","DIVIDE",
"UMINUS","COMPARISON","commands","@1","@2","final_semicolon","command","check_table",
"create_database","create_table","column_definition_commalist","column_definition",
"@3","column_type","column_type_options","opt_column_options_list","opt_column_options",
"table_constraint_definition","deletetbl","drop_database","drop_table","insert",
"insert_values_commalist","insert_values","optimize_table","rename_table","table_rename_table_commalist",
"table_rename_table","select","opt_select_all_distinct","select_ident_or_joker",
"select_list_ident","show_columns","update","update_values_commalist","update_values",
"use","if_exists","if_not_exists","table_ident_commalist","table_ident","column_commalist",
"column","opt_where","condition","predicate","comparison_predicate","scalar_exp",
"atom","literal","column_ref","subquery","between_predicate","like_predicate",
"test_for_null","in_predicate","atom_commalist","existence_test",""
};
#endif

static const short yyr1[] = {     0,
   240,   239,   241,   239,   242,   242,   243,   243,   243,   243,
   243,   243,   243,   243,   243,   243,   243,   243,   243,   244,
   245,   246,   247,   247,   249,   248,   248,   250,   250,   250,
   250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
   250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
   250,   250,   251,   251,   251,   251,   252,   252,   253,   253,
   253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
   255,   256,   257,   258,   259,   259,   260,   260,   261,   262,
   263,   263,   264,   265,   266,   266,   266,   267,   267,   268,
   268,   269,   270,   271,   271,   272,   272,   273,   274,   274,
   275,   275,   276,   276,   276,   277,   277,   278,   278,   278,
   279,   279,   279,   280,   280,   281,   281,   281,   281,   281,
   282,   282,   282,   282,   282,   282,   283,   283,   284,   284,
   284,   284,   284,   284,   284,   284,   284,   285,   286,   286,
   286,   287,   287,   287,   288,   289,   289,   290,   290,   291,
   291,   292,   292,   292,   292,   293,   293,   294
};

static const short yyr2[] = {     0,
     0,     3,     0,     4,     0,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
     4,     7,     1,     3,     0,     4,     1,     1,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     0,     2,     1,     1,     0,     2,     1,     2,
     3,     4,     2,     4,     2,     4,     4,     5,    10,     4,
     4,     4,     4,     7,     1,     3,     1,     1,     3,     3,
     1,     3,     3,     6,     0,     1,     1,     1,     1,     1,
     3,     4,     5,     1,     3,     3,     3,     2,     0,     2,
     0,     3,     0,     1,     3,     1,     3,     0,     1,     3,
     1,     3,     5,     0,     2,     3,     3,     2,     3,     1,
     1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
     3,     3,     2,     2,     1,     1,     3,     1,     1,     1,
     1,     1,     3,     5,     3,     6,     5,     4,     3,     4,
     3,     6,     5,     6,     5,     1,     3,     2
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     0,    85,     0,   103,
     0,     0,     1,     7,     8,     9,    10,    11,    12,    13,
    14,    17,    15,    16,    18,    19,   103,   101,   101,   103,
    99,    99,     0,   103,     0,    86,    87,     0,     0,   106,
     0,   104,    98,     3,     0,    20,     0,     0,     0,   114,
     0,     0,   103,     0,    79,    80,    81,     0,    90,    89,
     0,    88,   103,     0,     0,     0,     5,     2,     0,    21,
     0,     0,    71,   100,    72,    73,     0,     0,     0,   103,
     0,    92,   107,     0,   114,    94,   105,     6,     4,   102,
     0,     0,   139,   140,   141,   142,     0,     0,     0,     0,
   115,   120,   121,     0,   135,   138,   136,   122,   123,   124,
   125,   126,     0,    82,    83,   114,    91,     0,     0,    93,
     0,     0,     0,     0,    25,     0,    23,    27,     0,   158,
     0,     0,     0,   118,     0,   133,   136,   134,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    78,     0,    75,    77,    84,    97,    96,    95,     0,     0,
     0,   108,     0,     0,    22,     0,   143,   119,   137,     0,
   116,   117,     0,     0,   149,     0,     0,     0,   129,   130,
   131,   132,     0,   127,   128,   151,     0,     0,    74,     0,
   108,   108,   111,     0,   109,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    28,    53,    53,
    57,    24,   145,     0,     0,   156,     0,     0,     0,     0,
   148,   150,    76,    70,     0,     0,     0,     0,    67,    55,
    56,    33,    46,    43,    39,    42,    37,    35,    36,    31,
    32,    48,    52,    47,    30,    51,    38,    34,    29,    50,
    40,    41,    45,    49,    44,    26,   144,   147,   153,     0,
   155,     0,     0,     0,     0,    68,   112,   110,    54,     0,
     0,    59,     0,     0,    58,   157,   146,   152,   154,     0,
     0,     0,    63,   103,    65,    60,     0,   113,     0,     0,
     0,    61,   108,    64,    66,    62,     0,    69,     0,     0
};

static const short yydefgoto[] = {    12,
    45,    67,    89,    13,    14,    15,    16,   126,   127,   163,
   221,   242,   266,   285,   128,    17,    18,    19,    20,   152,
   153,    21,    22,    56,    57,    23,    38,    61,    62,    24,
    25,    85,    86,    26,    52,    48,    41,    42,   194,   195,
    73,   101,   102,   103,   104,   105,   106,   137,   130,   108,
   109,   110,   111,   228,   112
};

static const short yypact[] = {    36,
  -158,   -30,   -43,   -29,   -61,  -137,  -136,    21,    30,  -175,
  -165,     9,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  -175,    18,    18,  -175,
    45,    45,  -175,  -175,  -175,-32768,-32768,  -170,     7,  -153,
  -144,-32768,-32768,-32768,  -111,   -88,   -94,   -59,  -175,  -186,
    87,   -48,  -175,   -46,   -88,   -42,-32768,     0,-32768,-32768,
   112,   -34,  -175,   -28,   -22,  -175,   -13,-32768,   143,-32768,
   -11,    46,-32768,-32768,-32768,   -88,    -1,  -175,  -175,  -175,
    10,   -88,-32768,     4,  -164,-32768,-32768,-32768,-32768,-32768,
   -18,    28,-32768,-32768,-32768,    38,    46,    46,   -60,   -60,
  -200,-32768,-32768,    -3,-32768,-32768,   157,-32768,-32768,-32768,
-32768,-32768,   -89,-32768,-32768,  -186,-32768,  -105,   -22,-32768,
    40,   163,   170,    47,-32768,  -163,-32768,-32768,   113,-32768,
    51,   -82,   -10,-32768,   -60,-32768,-32768,-32768,    46,    46,
   -60,    53,   -23,    48,   -60,   -60,   -60,   -60,   101,  -115,
-32768,  -133,-32768,-32768,-32768,-32768,    15,-32768,    46,    56,
    57,    60,    73,   -18,-32768,    58,    68,-32768,-32768,  -126,
    59,-32768,  -143,  -152,-32768,   -60,    63,   -23,-32768,-32768,
-32768,-32768,   -83,    15,-32768,-32768,   186,   -89,-32768,   -15,
    60,    60,   107,  -103,-32768,  -171,  -171,  -171,  -171,  -171,
  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
  -171,  -171,  -171,  -171,  -171,  -171,  -171,-32768,  -171,  -171,
-32768,-32768,-32768,    95,   -60,-32768,    93,   -71,   -52,  -152,
-32768,-32768,-32768,-32768,   -68,   -41,   105,    60,-32768,   116,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -19,-32768,    15,-32768,   -23,
-32768,   -60,   103,    -9,   184,-32768,   117,-32768,-32768,   109,
   -23,-32768,   -51,   207,-32768,-32768,    15,-32768,-32768,   114,
   115,    46,-32768,  -175,-32768,  -123,   118,-32768,    24,    11,
   239,-32768,    60,-32768,-32768,-32768,    16,-32768,   343,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   332,-32768,-32768,-32768,-32768,   181,-32768,
-32768,   100,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   159,-32768,-32768,-32768,   270,  -106,-32768,-32768,-32768,-32768,
-32768,-32768,   230,-32768,   318,   322,   -27,   -31,  -176,   119,
   -64,   -85,-32768,-32768,   147,   -76,-32768,   -58,  -130,-32768,
-32768,-32768,-32768,   122,-32768
};


#define	YYLAST		419


static const short yytable[] = {    46,
   141,    54,    50,    58,   280,   121,    55,   141,   309,    28,
    31,   132,   134,   107,   235,   236,   186,    71,   185,   301,
   120,    65,   166,    27,    36,    76,   156,    72,   240,   139,
   140,   281,     1,    30,    87,    82,   154,    33,   107,   107,
    66,     2,   151,   227,    34,    35,    58,   115,   241,    72,
    40,   155,   116,   171,   172,    59,    39,   122,   176,     1,
    43,     3,   119,   164,    60,   165,   175,    64,     2,     4,
    93,    94,    95,   190,   302,   129,   166,    37,   142,     8,
   107,   107,    66,    63,   196,   142,   197,   225,     3,   145,
   146,   147,   148,   188,   198,   189,     4,   226,   143,   273,
   107,   231,   169,     5,    47,   143,   145,   146,   147,   148,
    68,   154,   282,    92,   199,   200,   187,    93,    94,    95,
    96,   201,   135,   238,   123,   239,   307,    99,   100,   283,
     5,    51,   202,    93,    94,    95,   177,    69,    66,    93,
    94,    95,    96,     6,   135,   203,   168,   139,   140,    99,
   100,    29,    32,   226,    74,   270,   178,   271,   238,     7,
   275,    77,    93,    94,    95,    96,    70,   135,   204,   205,
     6,     8,    99,   100,    40,     9,   294,    75,   272,   124,
   145,   146,   147,   148,    78,   238,     7,   276,    80,   206,
   207,    79,    81,   286,   208,   209,   210,    83,     8,    93,
    94,    95,     9,    84,   293,   211,   299,   125,    88,    10,
    90,    11,   284,   234,   139,   140,    91,   270,   169,   289,
   212,   144,   145,   146,   147,   148,   113,   149,   144,   145,
   146,   147,   148,   107,   149,   117,    10,    66,    11,   305,
   213,   118,   238,   133,   308,   136,   138,   145,   146,   147,
   148,   295,   304,   139,   140,   129,   150,   214,   131,   215,
   216,   217,   218,   219,   157,   160,   300,   159,    93,    94,
    95,    96,   161,    97,   162,     8,   167,    98,    99,   100,
   174,   170,   220,   191,   192,   193,   223,   173,   224,   140,
   230,   179,   180,   181,   182,   184,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,   263,   232,   264,   265,
   267,   269,   229,    93,    94,    95,    96,   237,   183,   170,
   277,   288,   290,    99,   100,   279,   292,   291,   296,   297,
   298,   306,   310,    44,   222,   303,   233,   114,   158,    53,
    49,   274,     0,     0,     0,     0,   278,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   287
};

static const short yycheck[] = {    27,
    11,    33,    30,    35,    24,    24,    34,    11,     0,    40,
    40,    97,    98,    72,   191,   192,   132,    49,   149,   143,
    85,   166,   129,   182,     4,    53,   132,   214,   200,   230,
   231,    51,    24,    77,    66,    63,   113,    99,    97,    98,
   227,    33,   132,   174,   182,   182,    78,    79,   220,   214,
   226,   116,    80,   139,   140,   226,    27,    76,    11,    24,
   226,    53,   227,   227,   235,   229,   143,   221,    33,    61,
   223,   224,   225,   159,   198,   228,   183,    57,    89,   163,
   139,   140,   227,    77,    12,    89,    14,   231,    53,   233,
   234,   235,   236,   227,    22,   229,    61,   174,   109,   230,
   159,   178,   229,    95,    87,   109,   233,   234,   235,   236,
   222,   188,   132,    68,    42,    43,   232,   223,   224,   225,
   226,    49,   228,   227,   143,   229,   303,   233,   234,   149,
    95,    87,    60,   223,   224,   225,    89,   232,   227,   223,
   224,   225,   226,   135,   228,    73,   229,   230,   231,   233,
   234,   182,   182,   230,    68,   227,   109,   229,   227,   151,
   229,   208,   223,   224,   225,   226,   226,   228,    96,    97,
   135,   163,   233,   234,   226,   167,   228,   226,   231,   198,
   233,   234,   235,   236,   227,   227,   151,   229,    77,   117,
   118,   192,   227,   270,   122,   123,   124,   226,   163,   223,
   224,   225,   167,   226,   281,   133,   292,   226,   222,   201,
    68,   203,   232,   229,   230,   231,   228,   227,   229,   229,
   148,   232,   233,   234,   235,   236,   228,   238,   232,   233,
   234,   235,   236,   292,   238,   226,   201,   227,   203,   229,
   168,   238,   227,    97,   229,    99,   100,   233,   234,   235,
   236,   283,   229,   230,   231,   228,   100,   185,   221,   187,
   188,   189,   190,   191,   118,   103,   294,   228,   223,   224,
   225,   226,   103,   228,   228,   163,   226,   232,   233,   234,
   228,   135,   210,   228,   228,   226,   229,   141,   221,   231,
   228,   145,   146,   147,   148,   149,   197,   198,   199,   200,
   201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
   211,   212,   213,   214,   215,   216,   217,   132,   219,   220,
   226,   229,   176,   223,   224,   225,   226,   221,   228,   183,
   226,   229,   149,   233,   234,   220,   228,   221,   132,   226,
   226,   103,     0,    12,   164,   228,   188,    78,   119,    32,
    29,   230,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 125 "sql.y"
{ end_query(); ;
    break;}
case 3:
#line 126 "sql.y"
{ end_query(); ;
    break;}
case 20:
#line 165 "sql.y"
{
   checktable(&gl_query,&gl_result);
;
    break;}
case 21:
#line 173 "sql.y"
{
   addIdentElement("",yyvsp[0].string,&gl_query);
   createdatabase(&gl_query,&gl_result);
;
    break;}
case 22:
#line 182 "sql.y"
{
   createtable(&gl_query,&gl_result);
;
    break;}
case 25:
#line 193 "sql.y"
{ AddColumnDefinition(yyvsp[0].string, &gl_query); ;
    break;}
case 28:
#line 198 "sql.y"
{ SetColumnDefinitionType(TYPE_TINYINT, &gl_query); SetColumnDefinitionSize(1, &gl_query) ;
    break;}
case 29:
#line 199 "sql.y"
{ SetColumnDefinitionType(TYPE_SMALLINT, &gl_query); SetColumnDefinitionSize(1, &gl_query) ;
    break;}
case 30:
#line 200 "sql.y"
{ SetColumnDefinitionType(TYPE_MEDIUMINT, &gl_query); SetColumnDefinitionSize(2, &gl_query) ;
    break;}
case 31:
#line 201 "sql.y"
{ SetColumnDefinitionType(TYPE_INT, &gl_query); SetColumnDefinitionSize(2, &gl_query) ;
    break;}
case 32:
#line 202 "sql.y"
{ SetColumnDefinitionType(TYPE_INTEGER, &gl_query); SetColumnDefinitionSize(2, &gl_query) ;
    break;}
case 33:
#line 203 "sql.y"
{ SetColumnDefinitionType(TYPE_BIGINT, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 34:
#line 204 "sql.y"
{ SetColumnDefinitionType(TYPE_REAL, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 35:
#line 205 "sql.y"
{ SetColumnDefinitionType(TYPE_DOUBLE, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 36:
#line 206 "sql.y"
{ SetColumnDefinitionType(TYPE_FLOAT, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 37:
#line 207 "sql.y"
{ SetColumnDefinitionType(TYPE_DECIMAL, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 38:
#line 208 "sql.y"
{ SetColumnDefinitionType(TYPE_NUMERIC, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 39:
#line 209 "sql.y"
{ SetColumnDefinitionType(TYPE_DATE, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 40:
#line 210 "sql.y"
{ SetColumnDefinitionType(TYPE_TIME, &gl_query); SetColumnDefinitionSize(3, &gl_query) ;
    break;}
case 41:
#line 211 "sql.y"
{ SetColumnDefinitionType(TYPE_TIMESTAMP, &gl_query); SetColumnDefinitionSize(4, &gl_query) ;
    break;}
case 42:
#line 212 "sql.y"
{ SetColumnDefinitionType(TYPE_DATETIME, &gl_query); SetColumnDefinitionSize(7, &gl_query) ;
    break;}
case 43:
#line 213 "sql.y"
{ SetColumnDefinitionType(TYPE_CHAR, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 44:
#line 214 "sql.y"
{ SetColumnDefinitionType(TYPE_VARCHAR, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 45:
#line 215 "sql.y"
{ SetColumnDefinitionType(TYPE_TINYBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 46:
#line 216 "sql.y"
{ SetColumnDefinitionType(TYPE_BLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 47:
#line 217 "sql.y"
{ SetColumnDefinitionType(TYPE_MEDIUMBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 48:
#line 218 "sql.y"
{ SetColumnDefinitionType(TYPE_LONGBLOB, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 49:
#line 219 "sql.y"
{ SetColumnDefinitionType(TYPE_TINYTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 50:
#line 220 "sql.y"
{ SetColumnDefinitionType(TYPE_TEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 51:
#line 221 "sql.y"
{ SetColumnDefinitionType(TYPE_MEDIUMTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 52:
#line 222 "sql.y"
{ SetColumnDefinitionType(TYPE_LONGTEXT, &gl_query); SetColumnDefinitionSize(255, &gl_query) ;
    break;}
case 54:
#line 227 "sql.y"
{ SetColumnDefinitionFlag(FLAG_UNSIGNED | FLAG_ZEROFILL,1,&gl_query); ;
    break;}
case 55:
#line 228 "sql.y"
{ SetColumnDefinitionFlag(FLAG_UNSIGNED,1,&gl_query); ;
    break;}
case 56:
#line 229 "sql.y"
{ SetColumnDefinitionFlag(FLAG_ZEROFILL,1,&gl_query); ;
    break;}
case 59:
#line 239 "sql.y"
{ SetColumnDefinitionFlag(FLAG_NULL,1,&gl_query); ;
    break;}
case 60:
#line 240 "sql.y"
{ SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); ;
    break;}
case 61:
#line 241 "sql.y"
{ SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); /* create_index(); */ ;
    break;}
case 62:
#line 242 "sql.y"
{ SetColumnDefinitionFlag(FLAG_NULL,0,&gl_query); /* create_index(); */ ;
    break;}
case 63:
#line 243 "sql.y"
{ SetColumnDefaultValue(yyvsp[0].data, &gl_query); FREE_DATA(yyvsp[0].data);;
    break;}
case 64:
#line 244 "sql.y"
{;
    break;}
case 65:
#line 245 "sql.y"
{;
    break;}
case 66:
#line 246 "sql.y"
{;
    break;}
case 71:
#line 260 "sql.y"
{
   deletetbl(&gl_query, &gl_result);
;
    break;}
case 72:
#line 268 "sql.y"
{
   addIdentElement("",yyvsp[0].string,&gl_query);
   dropdatabase(&gl_query,&gl_result);
;
    break;}
case 73:
#line 277 "sql.y"
{
   droptable(&gl_query,&gl_result);
;
    break;}
case 74:
#line 286 "sql.y"
{
   insert(&gl_query, &gl_result);
;
    break;}
case 77:
#line 298 "sql.y"
{
        AddData(yyvsp[0].data, &gl_query);
        gl_query.nbcols++;  
        FREE_DATA(yyvsp[0].data);
    ;
    break;}
case 78:
#line 304 "sql.y"
{
        AddDataVide(&gl_query);
        gl_query.nbcols++;  
    ;
    break;}
case 79:
#line 313 "sql.y"
{
   optimizetable(&gl_query, &gl_result);
;
    break;}
case 80:
#line 321 "sql.y"
{
   renametbl(&gl_query, &gl_result);
;
    break;}
case 84:
#line 338 "sql.y"
{
  select(&gl_query,&gl_result);
;
    break;}
case 89:
#line 351 "sql.y"
{;
    break;}
case 90:
#line 356 "sql.y"
{
        AddColumnToList(&gl_query,yyvsp[0].string,"","");    
    ;
    break;}
case 91:
#line 360 "sql.y"
{
        AddColumnToList(&gl_query,yyvsp[0].string,"","");    
    ;
    break;}
case 92:
#line 368 "sql.y"
{
    show_columns(&gl_query, &gl_result);
;
    break;}
case 93:
#line 376 "sql.y"
{
update(&gl_query, &gl_result);
;
    break;}
case 96:
#line 386 "sql.y"
{;
    break;}
case 97:
#line 387 "sql.y"
{;
    break;}
case 98:
#line 393 "sql.y"
{
    addIdentElement("",yyvsp[0].string,&gl_query);
    usedb(&gl_query, &gl_result);
;
    break;}
case 99:
#line 401 "sql.y"
{ gl_query.if_exists = 0; ;
    break;}
case 100:
#line 403 "sql.y"
{ gl_query.if_exists = 1; ;
    break;}
case 101:
#line 407 "sql.y"
{ gl_query.if_not_exists = 0; ;
    break;}
case 102:
#line 409 "sql.y"
{ gl_query.if_not_exists = 1; ;
    break;}
case 106:
#line 418 "sql.y"
{ addIdentElement(yyvsp[0].string,"",&gl_query); ;
    break;}
case 107:
#line 419 "sql.y"
{ addIdentElement(yyvsp[0].string,yyvsp[-2].string,&gl_query); ;
    break;}
case 111:
#line 428 "sql.y"
{;
    break;}
case 112:
#line 429 "sql.y"
{;
    break;}
case 113:
#line 430 "sql.y"
{;
    break;}
case 115:
#line 435 "sql.y"
{ DebugShowWhereResult(yyvsp[0].where_clause); free_result(yyvsp[0].where_clause); ;
    break;}
case 116:
#line 439 "sql.y"
{ yyval.where_clause=yyvsp[-2].where_clause; ;
    break;}
case 117:
#line 440 "sql.y"
{ yyval.where_clause=yyvsp[-2].where_clause; ;
    break;}
case 118:
#line 441 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 119:
#line 442 "sql.y"
{ yyval.where_clause=yyvsp[-1].where_clause; ;
    break;}
case 120:
#line 443 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 121:
#line 447 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 122:
#line 448 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 123:
#line 449 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 124:
#line 450 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 125:
#line 451 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 126:
#line 452 "sql.y"
{ yyval.where_clause=yyvsp[0].where_clause; ;
    break;}
case 127:
#line 456 "sql.y"
{ filter_comparison(&yyval.where_clause, yyvsp[-2].data,yyvsp[0].data,yyvsp[-1].subtok, &gl_query); FREE_DATA(yyvsp[-2].data); FREE_DATA(yyvsp[0].data); ;
    break;}
case 128:
#line 457 "sql.y"
{ /* subquery */ ;
    break;}
case 129:
#line 461 "sql.y"
{ AddUnivData(yyvsp[-2].data, yyvsp[0].data, &yyval.data);  ;
    break;}
case 130:
#line 462 "sql.y"
{ SubUnivData(yyvsp[-2].data, yyvsp[0].data, &yyval.data);  ;
    break;}
case 131:
#line 463 "sql.y"
{ TimesUnivData(yyvsp[-2].data, yyvsp[0].data, &yyval.data);;
    break;}
case 132:
#line 464 "sql.y"
{ DivUnivData(yyvsp[-2].data, yyvsp[0].data, &yyval.data);  ;
    break;}
case 133:
#line 465 "sql.y"
{ yyval.data=yyvsp[0].data;                     ;
    break;}
case 134:
#line 466 "sql.y"
{ UMinusUnivData(yyvsp[0].data,&yyval.data);    ;
    break;}
case 135:
#line 467 "sql.y"
{ yyval.data=yyvsp[0].data;                     ;
    break;}
case 136:
#line 468 "sql.y"
{ yyval.data=yyvsp[0].data;                     ;
    break;}
case 137:
#line 469 "sql.y"
{ yyval.data=yyvsp[-1].data;                     ;
    break;}
case 138:
#line 473 "sql.y"
{ yyval.data=yyvsp[0].data; ;
    break;}
case 139:
#line 477 "sql.y"
{ yyval.data.data.string=strdup(yyvsp[0].string); yyval.data.type=CHAINE;   ;
    break;}
case 140:
#line 478 "sql.y"
{ yyval.data.data.floatNumber=yyvsp[0].floatNumber;    yyval.data.type=FLOTTANT; ;
    break;}
case 141:
#line 479 "sql.y"
{ yyval.data.data.number=yyvsp[0].number;         yyval.data.type=ENTIER;   ;
    break;}
case 142:
#line 483 "sql.y"
{ yyval.data.data.col_ref=strdup(yyvsp[0].string); yyval.data.type=COLONNE_REF; ;
    break;}
case 143:
#line 484 "sql.y"
{ yyval.data.data.col_ref=strdup(yyvsp[0].string); yyval.data.type=COLONNE_REF; ;
    break;}
case 144:
#line 485 "sql.y"
{ yyval.data.data.col_ref=strdup(yyvsp[0].string); yyval.data.type=COLONNE_REF; ;
    break;}
case 145:
#line 489 "sql.y"
{ /* jointure nécessaires */ ;
    break;}
case 146:
#line 493 "sql.y"
{ /* filter_between() */ ;
    break;}
case 147:
#line 494 "sql.y"
{ /* filter_not_between() */ ;
    break;}
case 148:
#line 498 "sql.y"
{ /* filter_not_like() */ ;
    break;}
case 149:
#line 499 "sql.y"
{ /* filter_like() */ ;
    break;}
case 150:
#line 503 "sql.y"
{ /* filter_is_not_null() */ ;
    break;}
case 151:
#line 504 "sql.y"
{ /* filter_is_null() */ ;
    break;}
case 152:
#line 508 "sql.y"
{ /* subquery */ ;
    break;}
case 153:
#line 509 "sql.y"
{ /* subquery */ ;
    break;}
case 154:
#line 510 "sql.y"
{ /* filter_not_in()*/ ;
    break;}
case 155:
#line 511 "sql.y"
{ /* filter_in()*/ ;
    break;}
case 156:
#line 515 "sql.y"
{;
    break;}
case 157:
#line 516 "sql.y"
{;
    break;}
case 158:
#line 519 "sql.y"
{ /* subquery */ ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 521 "sql.y"

