/*
** types.c for epiDatabase
**
** Made by Julien Assémat
** Login   moular_t
**
** Started on  01/01/2005 assema_j
** Last update 26/02/2005 moular_t
*/

#include "types.h"

/*
** Delete first and last char
*/
void unquote(char * str)
{
     char *prev,*s;
     
     s=prev=str;
     s++;
     while(*s!=0)
     {
        *prev=*s;
        
        prev++;
        s++;
     }
     str[prev-str-1]=0;
}

void unquote_string(char * str)
{
     char *prev,*s;
     
     s=prev=str;
     s++;

     *prev=*s;
     prev++;
     s++;
     while((*s!=0) && (*prev!='\''))
     {
        *prev=*s;
        
        prev++;
        s++;
     }
     str[prev-str-1]=0;
}

/*
** Initialize structure
*/
void init_sql_query(struct s_sql_query *query)
{
     query->identlist     = NULL;
     query->datalist     = NULL;
     query->fieldlist     = NULL;
     query->table         = NULL;
     query->nbcols        = 0 ;
     query->if_exists     = 0 ;
     query->if_not_exists = 0 ;
}
/*
** Initialize structure
*/
void init_sql_result(struct s_sql_result *result)
{
   result->error_code = 0 ;
}

/*
** Init p_Table
*/
void init_p_table(p_table * table)
{
    /*p_table  tbl;
    while(*table)
     {
        tbl = *table;
        table = &((*table)->next);
        free(tbl);
     }*/
    *table = NULL;
}

/*
** Reinitialize structure
*/
void reinit_sql_query(struct s_sql_query *query)
{
     p_lident lident;
     p_ldata  ldata;
     p_lfield  lfield;
     p_table  tbl;
     
     while(query->identlist)
     {
        lident=query->identlist;
        query->identlist=lident->next;
        free(lident);
     }

     query->identlist     = NULL;
     
     while(query->datalist != NULL)
     {
        ldata=query->datalist;
        query->datalist = query->datalist->next;
        free(ldata);
     }
     query->datalist     = NULL;
     
     while(query->fieldlist != NULL)
     {
        lfield=query->fieldlist;
        query->fieldlist = query->fieldlist->next;
        free(lfield);
     }
     query->fieldlist     = NULL;
     
     while(query->table)
     {
        tbl=query->table;
        query->table=query->table->next;
        free(tbl);
     }

     query->table         = NULL ;
     query->nbcols        = 0 ;
     query->if_exists     = 0 ;
     query->if_not_exists = 0 ;
}

/*
** Reinitialize structure
*/
void reinit_sql_result(struct s_sql_result *result)
{
   result->error_code = 0 ;
}

/*
** Add table to table name
*/
void addIdentElement(t_tblname tblname, t_dbname dbname, struct s_sql_query *query)
{
     p_lident elt, cur_elt;
     elt=malloc(sizeof(struct s_lident));
     strcpy(elt->tbl_name,tblname);
     
     if(*dbname==0)
        strcpy(elt->db_name,query->default_dbname);
     else
        strcpy(elt->db_name,dbname);
     elt->next=NULL;
     
     if(!query->identlist)
        query->identlist=elt;
     else {
        cur_elt=query->identlist;     
        while(cur_elt->next)
           cur_elt=cur_elt->next;
        cur_elt->next=elt;
     }
}

char * getFirstTblName(struct s_sql_query *query)
{
     if(query->identlist==NULL)
        return(0);
     else
        return(query->identlist->tbl_name);
}

char * getFirstDbName(struct s_sql_query *query)
{
     if(query->identlist==NULL)
        return(0);
     else
        return(query->identlist->db_name);
}

void DebugShowIdentList(struct s_sql_query *query)
{
     int i;
     p_lident elt;
     elt=query->identlist;
     i=0;
     printf("= DebugShowIdentList =\n");
     while(elt!=NULL)
     {
        printf("| %s | %s |\n", elt->db_name, elt->tbl_name);
        elt=elt->next;
        i++;
     }
     printf("= DebugShowIdentList: %d elements =\n",i);
}


void DebugShowTable(struct s_sql_query *query)
{
     int i;
     p_table elt;
     elt=query->table;
     i=0;
     printf("= DebugShowTable =\n");
     while(elt!=NULL)
     {
        printf("| %s | %d | %d |\n", elt->column.name, elt->column.size, elt->column.flags);
        elt=elt->next;
        i++;
     }
     printf("= DebugShowTable: %d elements =\n",i);
}



void AddUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res)
{
     if(l.type!=r.type)
     {
        (*res).type=ENTIER;
        (*res).data.number=0;
     }
     switch(l.type)
     {
        case ENTIER:
             (*res).data.number = l.data.number+r.data.number;
             break;
        case FLOTTANT:
             (*res).data.floatNumber = l.data.floatNumber+r.data.floatNumber;
             break;
        case CHAINE:
             (*res).data.string=malloc(sizeof(char)*(strlen(l.data.string)+strlen(r.data.string)) );
             strcpy((*res).data.string, l.data.string);
             strcat((*res).data.string, r.data.string);
             break;

        case VIDE:
        default:
             (*res).type=VIDE;
             break;        
     }
}

void SubUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res)
{
     if(l.type!=r.type)
     {
        (*res).type=ENTIER;
        (*res).data.number=0;
     }
     switch(l.type)
     {
        case ENTIER:
             (*res).data.number = l.data.number-r.data.number;
             break;
        case FLOTTANT:
             (*res).data.floatNumber = l.data.floatNumber-r.data.floatNumber;
             break;

        case CHAINE:
        case VIDE:
        default:
             (*res).type=VIDE;
             break;        
     }
}

void UMinusUnivData(struct s_univdata l, struct s_univdata *res)
{
     switch(l.type)
     {
        case ENTIER:
             (*res).data.number = -l.data.number;
             break;
        case FLOTTANT:
             (*res).data.floatNumber = -l.data.floatNumber;
             break;

        case CHAINE:
        case VIDE:
        default:
             (*res).type=VIDE;
             break;        
     }
}

void TimesUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res)
{
     if(l.type!=r.type)
     {
        (*res).type=ENTIER;
        (*res).data.number=0;
     }
     switch(l.type)
     {
        case ENTIER:
             (*res).data.number = l.data.number*r.data.number;
             break;
        case FLOTTANT:
             (*res).data.floatNumber = l.data.floatNumber*r.data.floatNumber;
             break;

        case CHAINE:
        case VIDE:
        default:
             (*res).type=VIDE;
             break;        
     }
}

void DivUnivData(struct s_univdata l, struct s_univdata r, struct s_univdata *res)
{
     if(l.type!=r.type)
     {
        (*res).type=ENTIER;
        (*res).data.number=0;
     }
     switch(l.type)
     {
        case ENTIER:
             (*res).data.number = l.data.number/r.data.number;
             break;
        case FLOTTANT:
             (*res).data.floatNumber = l.data.floatNumber/r.data.floatNumber;
             break;

        case CHAINE:
        case VIDE:
        default:
             (*res).type=VIDE;
             break;        
     }
}
