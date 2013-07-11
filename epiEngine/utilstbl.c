/*
** createtbl.c for epiDatabase in /epiEngine
**
** Made by Julien Assémat
** Login   assema_j
**
** Started on  02/01/2005 assema_j
** Last update 26/02/2005 moular_t
*/

#include "utilstbl.h"

/*
** table exists?
*/
int tableexist(const char* database, const char *table)
{
   FILE *f;
   char filename[255];

    if((*database==0) || (*table==0))
       return(0);

   *filename=0;
   strcpy(filename, PATH_DATA);
   strcat(filename, database);
   strcat(filename, "\\");
   strcat(filename, table);
   strcat(filename, EXTENSION_TABLE);
   f=fopen(filename,"r");
   if(!f)
      return(0);
   else {
      fclose(f);
      return(1);
   }
}

int IsInTable(p_table List1, p_lfield List2)
{
    p_table Temp;
    
    Temp = List1;
    while(List2 != NULL)
    {
            List1 = Temp;
            while(List1 != NULL)
            {
                if(strcmp(List1->column.name, List2->field_name) == 0)
                    break;
                else
                    List1 = List1->next;    
            }
            if(List1 == NULL)
                return 0; 
            List2 = List2->next;
    }
    return 1;       
}

/*
** AddColumnToList
** Add a column name
*/
void AddColumnToList(struct s_sql_query *query, char * ColumnName, char * TableName, char * DatabaseName)
{
    p_lfield newColumn, Temp;
    
    newColumn = calloc(1, sizeof(struct s_lfield));
    strcpy(newColumn->field_name, ColumnName);
    newColumn->next = NULL;
    
    if(*DatabaseName == 0)
        strcpy(newColumn->db_name, query->default_dbname);
     else
        strcpy(newColumn->db_name, DatabaseName);

    strcpy(newColumn->tbl_name, TableName);
    
    
    if(query->fieldlist == NULL)
        query->fieldlist = newColumn;
    else
    {
        Temp = query->fieldlist;
        while(Temp->next != NULL)
            Temp = Temp->next;
        Temp->next = newColumn;
    }   
}


/*
** Clear row
** Fill a row with zero
*/
void ClearRow(FILE *f, long start, long size)
{
     long restore_address;
     char nul;

     if(!f)
        return;

     restore_address=ftell(f);
     fseek(f,start,SEEK_SET);
     nul=0;
     fwrite(&nul,sizeof(char),size,f);
     fseek(f,restore_address,SEEK_SET);
}

/*
** COLUMN TYPE 2 BASIC TYPE
*/
e_basic_type colType2basicType(int colType)
{
   switch(colType)
   {
      case TYPE_TINYINT:           return ENTIER;
      case TYPE_SMALLINT:          return ENTIER;
      case TYPE_MEDIUMINT:         return ENTIER;
      case TYPE_INT:               return ENTIER;
      case TYPE_INTEGER:           return ENTIER;
      case TYPE_BIGINT:            return ENTIER;
      case TYPE_REAL:              return FLOTTANT;
      case TYPE_DOUBLE:            return FLOTTANT;
      case TYPE_FLOAT:             return FLOTTANT;
      case TYPE_DECIMAL:           return ENTIER;
      case TYPE_NUMERIC:           return ENTIER;
      case TYPE_DATE:              return CHAINE;
      case TYPE_TIME:              return CHAINE;
      case TYPE_TIMESTAMP:         return ENTIER;
      case TYPE_DATETIME:          return ENTIER;
      case TYPE_CHAR:              return CHAINE;
      case TYPE_VARCHAR:           return CHAINE;
      case TYPE_TINYBLOB:          return CHAINE;
      case TYPE_BLOB:              return CHAINE;
      case TYPE_MEDIUMBLOB:        return CHAINE;
      case TYPE_LONGBLOB:          return CHAINE;
      case TYPE_TINYTEXT:          return CHAINE;
      case TYPE_TEXT:              return CHAINE;
      case TYPE_MEDIUMTEXT:        return CHAINE;
      case TYPE_LONGTEXT:          return CHAINE;
      default:                     return VIDE;
   }
}

p_lrow init_result(struct s_sql_query *query)
{
   p_lrow result;
   p_lrow cur_elt,elt;
   int row_size;
   long i, count_rows, file_size;

   p_table tbl_struct, cur_col;
   FILE * f;
   char filename_data[S_TABLE+strlen(EXTENSION_DATA)-1]; 


   result=NULL;

   if(count_rows==0)
      return result;

   /* Get Row size */
   tbl_struct=GetTableDefinition(getFirstDbName(query), getFirstTblName(query));
   cur_col=tbl_struct;
   row_size=0;
   while(cur_col)
   {
       row_size += cur_col->column.size;
       cur_col=cur_col->next;
   }
   freeTableDefinition(tbl_struct);
   /* Get File size */
   *filename_data = 0;
   strcpy(filename_data, PATH_DATA);
   strcat(filename_data, getFirstDbName(query));
   strcat(filename_data, "\\");
   strcat(filename_data, getFirstTblName(query));
   strcat(filename_data, EXTENSION_DATA);
   f=fopen(filename_data,"r");
   if(!f)
      return result;
   fseek(f,0,SEEK_END);
   file_size=ftell(f);
   fclose(f);
   if(file_size==0)
      return NULL;
      
   /* Row size */
   count_rows=file_size/row_size;
     
   result=malloc(sizeof(struct s_lrow));

   result->row_id=0;
     
   cur_elt=result;
   i=1;
   while(i<count_rows)
   {
      elt=malloc(sizeof(struct s_lrow));
      elt->row_id=i;
      elt->next=NULL;
        
      cur_elt->next=elt;
      cur_elt=elt;
      i++;
   }
     
   return result;
}
void free_result(p_lrow result)
{
   p_lrow next;
   while(result)
   {
      next=result->next;
      free(result);
      result=next;
   }
}

/* FIXME: A débugguer! COLONNE RECONNU COMME CHAINE!!! */
void filter_comparison(p_lrow *result, struct s_univdata lexp, struct s_univdata rexp, char comparison, struct s_sql_query *query)
{
   FILE * f;
   char filename_data[S_TABLE+strlen(EXTENSION_DATA)-1]; 
   p_table tbl_struct, cur_col;
   p_lrow cur_elt, prec;
   char condition_ok;

   long row_size, offset;
   
   *result=init_result(query);
   
   
   /* Get Row size */
   tbl_struct=GetTableDefinition(getFirstDbName(query), getFirstTblName(query));
   cur_col=tbl_struct;
   row_size=0;
   while(cur_col)
   {
       row_size += cur_col->column.size;
       cur_col=cur_col->next;
   }
   
   *filename_data = 0;
   strcpy(filename_data, PATH_DATA);
   strcat(filename_data, getFirstDbName(query));
   strcat(filename_data, "\\");
   strcat(filename_data, getFirstTblName(query));
   strcat(filename_data, EXTENSION_DATA);
   f=fopen(filename_data,"r");
   if(!f)
      return;

      
   cur_elt=*result;
   prec=NULL;
   while(cur_elt)
   {
      /* Replace column ref by data! */
      if(lexp.type==COLONNE_REF)
      {
         offset=0;
         cur_col=tbl_struct;
         while((cur_col)&&(strcmp(cur_col->column.name,lexp.data.col_ref)!=0))
         {
            cur_col=cur_col->next;
            offset += cur_col->column.size;
         }
         fseek(f,cur_elt->row_id*row_size+offset,SEEK_SET);
         lexp.type=colType2basicType(cur_col->column.type);
         switch(lexp.type)
         {
            case ENTIER:
                 fread(&lexp.data.number,cur_col->column.size,1,f);
                 break;
            case FLOTTANT:
                 fread(&lexp.data.floatNumber,sizeof(double),1,f);
                 break;
            case CHAINE:
                 lexp.data.string=malloc(cur_col->column.size+1);
                 fread(&lexp.data.string,cur_col->column.size,1,f);
                 lexp.data.string[cur_col->column.size]=0;
                 break;
            default:
                 break;
         }
      }
      
      if(rexp.type==COLONNE_REF)
      {
         offset=0;
         cur_col=tbl_struct;
         while((cur_col)&&(strcmp(cur_col->column.name,rexp.data.col_ref)!=0))
         {
            cur_col=cur_col->next;
            offset += cur_col->column.size;
         }
         fseek(f,cur_elt->row_id*row_size+offset,SEEK_SET);
         rexp.type=colType2basicType(cur_col->column.type);
         switch(rexp.type)
         {
            case ENTIER:
                 fread(&rexp.data.number,cur_col->column.size,1,f);
                 break;
            case FLOTTANT:
                 fread(&rexp.data.floatNumber,sizeof(double),1,f);
                 break;
            case CHAINE:
                 rexp.data.string=malloc(cur_col->column.size+1);
                 fread(&rexp.data.string,cur_col->column.size,1,f);
                 rexp.data.string[cur_col->column.size]=0;
                 break;
            default:
                 break;
         }
      }
      
      
      if(lexp.type==rexp.type)
      {
         condition_ok=0;
         switch(comparison)
         {
            case LESS:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number<rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber<rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)<0) condition_ok=1;
                    default:
                       break;
                 }
                 break;
            case GREAT:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number>rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber>rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)>0) condition_ok=1;
                    default:
                       break;
                 }
                 break;
            case LEQ:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number<=rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber<=rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)<=0) condition_ok=1;
                    default:
                       break;
                 }
                 break;
            case GEQ:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number>=rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber>=rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)>=0) condition_ok=1;
                    default:
                       break;
                 }
                 break;
            case NEQUAL:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number!=rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber!=rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)!=0) condition_ok=1;
                       break;
                    default:
                       break;
                 }
                 break;
            case EQUAL:
                 switch(lexp.type)
                 {
                    case ENTIER:
                       if(lexp.data.number==rexp.data.number) condition_ok=1;
                       break;
                    case FLOTTANT:
                       if(lexp.data.floatNumber==rexp.data.floatNumber) condition_ok=1;
                       break;
                    case CHAINE:
                       if(strcmp(lexp.data.string,rexp.data.string)==0) condition_ok=1;
                    default:
                       break;
                 }
                 break;
            default:
                 break;
         }
      }
      if(!condition_ok)
      { /* delete current element */
        if(prec==NULL)
        {
           *result=cur_elt->next;
           free(cur_elt);
           cur_elt=*result;
        } else {
           prec->next=cur_elt->next;
           free(cur_elt);
           cur_elt=prec->next;
        }
      } else {
         prec=cur_elt;
         cur_elt=cur_elt->next;
      }
   }
   
   freeTableDefinition(tbl_struct);
}

void DebugShowWhereResult(p_lrow where_res)
{
     int i;
     p_lrow elt;
     elt=where_res;
     i=0;
     printf("= DebugShowWhereResult =\n");
     while(elt!=NULL)
     {
        printf("| %d |\n", elt->row_id);
        elt=elt->next;
        i++;
     }
     printf("= DebugShowWhereResult: %d elements =\n",i);
}

