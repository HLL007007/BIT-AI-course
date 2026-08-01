#include <stdio.h>
#include <stdlib.h>
  
struct node  
{
	int data;  
    struct node * next;  
};  
  
typedef struct node NODE; 
typedef struct node * PNODE;
 
PNODE constructlist( PNODE head, int num );
void outlist( PNODE head );
void deleteneg( PNODE head ); 
  
int main ( )  
{   int num=1;  
    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
           constructlist (head, num);  
    }
    // 删除负数  
    deleteneg( head );
    // 输出非 0 的数
    outlist( head );  
    return 0;  
}  
  
PNODE constructlist( PNODE head, int num )
{   PNODE p;
    p = (PNODE)malloc( sizeof(NODE) ); 
    p->data = num;
    p->next = head->next; 
    head->next = p;
    return head;
}

void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  

void deleteneg( PNODE head ){
    PNODE p , q;
    p = head;
    q = p -> next;
    while (q != NULL){
        if (q -> data < 0){
            p -> next = q -> next;
            free(q);
            q = p -> next;
        }
        else{
            p = q;
            q = q -> next;
        }
    }
}