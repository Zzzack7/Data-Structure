//
// Created by Administrator on 2022/3/9.
//

#ifndef LINEAR_LIST_LINEAR_LIST_H
#define LINEAR_LIST_LINEAR_LIST_H
#define MAXSIZE 1024

struct _T_linear_list {int a[MAXSIZE]; int a_len;};
typedef struct _T_linear_list linear_list_t;
typedef enum _T_error_t{NOERROR, OVERFLOW, SUBSCRIPT}error_t;
typedef int elem_t;

linear_list_t *Create(void);
void    Destroy(linear_list_t *L);
void    Set_null(linear_list_t *L);   /* empty list*/
int     Length(linear_list_t *L);     /* length of the list */
elem_t  Get(linear_list_t *L, int i); /* get the value */
error_t Insert(linear_list_t *L, elem_t x, int i); /* insert */
error_t Remove(linear_list_t *L, int i);		    /* remove */
int     Locate(linear_list_t *L, elem_t x);/* locate the pos.*/

#endif //LINEAR_LIST_LINEAR_LIST_H
