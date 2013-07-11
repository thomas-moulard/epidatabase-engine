/*
** msg_index.h for epiDatabase in /share
**
** Made by Thomas Moulard
** Login   moular_t
**
** Started on  01/01/2005 moular_t
** Last update 26/02/2005 moular_t
*/

#ifndef MSG_INDEX_H_
# define MSG_INDEX_H_

#define MSG_OK                              0

#define MSG_DATABASE_EXISTS                 1
#define MSG_DATABASE_NOT_EXISTS             2

#define MSG_TABLE_EXISTS                    3
#define MSG_TABLE_NOT_EXIST                 4
#define MSG_INVALID_CREATE_TABLE_DEFINITION 5

#define MSG_INVALID_DATABASE_NAME           6
#define MSG_INVALID_TABLE_NAME              7

#define MSG_CANT_ACCESS_TABLE_DATA          8
#define MSG_COLUMN_COUNT_NOT_MATCH          9
#define MSG_FIELD_CANT_BE_NULL              10
#define MSG_CANT_DELETE_TABLE               11
#define MSG_CANT_DELETE_TABLE_DATA          12

#define MSG_SYNTAX_ERROR                    13

#define MSG_INVALID_COLUMN_NAME             14


#endif /* !MSG_INDEX_H_ */
