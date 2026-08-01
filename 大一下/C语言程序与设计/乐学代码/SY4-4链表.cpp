#include <stdio.h>  
#include <stdlib.h>  
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE;  
  
NODE *MoveNode( NODE * );  
  
void SetLink( NODE *h )  
{  
    NODE *p=NULL, *q=NULL;  
    int m;  
    while(1)  
    {  
        scanf("%d",&m);  
        if( m == -1 )  
            return ;  
        p = (NODE *)malloc(sizeof(NODE));  
        p->no = m;  
        p->next = NULL;  
        if( h->next == NULL )  
        {  
            h->next = p;  
            q = p;  
        }  
        else  
        {  
            q->next = p;  
            q = q->next;  
        }  
    }  
    return;  
}  
  
int main( )  
{  
    NODE *head=NULL, *q=NULL;  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head );  
    q = MoveNode( head );  
    do  
    {  
        printf("%d ",q->next->no);  
        q = q->next;  
    }while( q->next != NULL );   
    printf("\n");  
    return 0;  
}  

NODE *MoveNode( NODE *head ){
    NODE *temp_head = (NODE*) malloc(sizeof(NODE));
    temp_head -> no = -1;  
    temp_head -> next = NULL;
    if ( head == NULL || head->next == NULL || head->next->next == NULL ) return head;
    NODE *p = head;
    NODE *q = head->next;
    NODE *temp = temp_head;
    while (p != NULL && q != NULL){
        if (q -> no % 2 == 0){
            p -> next = q -> next;
            q -> next = NULL;
            temp -> next = q;
            q = p -> next;
            temp = temp -> next;
            temp -> next = NULL;
        }else{
        p = p -> next;
        q = q -> next;
        }
    }
    p -> next = temp_head -> next;
    temp_head -> next = NULL;  
    free(temp_head);
    return head;
}