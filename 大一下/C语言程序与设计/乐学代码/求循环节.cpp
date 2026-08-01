#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );

void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do
		{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;

}

int main()
{   int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	pring = find( head, &n );
	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}

void change( int n, int m, NODE * head ){

    NODE **record = (NODE **)calloc(m, sizeof(NODE *));
    if (!record) return;

    NODE *tail = head;
    
    while (n > 0){
        if (record[n] != NULL) {
            tail->next = record[n];
            break;
        }
        int num = n * 10 / m;

        NODE *p = (NODE *)malloc( sizeof(NODE) );
        p->data = num;
        p -> next = NULL;

        record[n] = p;

        tail -> next = p;
        tail = p;

        n = n * 10 % m;
    }
    free(record);
}

NODE * find( NODE * head, int * n )
{
    if (head == NULL || head->next == NULL) {
        *n = 0; 
        return NULL;
}
    NODE *p = head->next;
    NODE *start = NULL;
    while (p != NULL){
        if (p -> data >= 10){
            start = p;
            break;
        }
        p -> data += 10;
        p = p -> next;
    }

    if (start == NULL){
        *n = 0;
        p = head -> next;
        while (p != NULL){
            p -> data -= 10;
            p = p -> next;
        }
        return NULL;
    }

    int count = 1;

    NODE *temp = start -> next;

    while (temp != start){
        count++;
        temp = temp -> next;
    }

    temp = head -> next;
    while (temp != NULL && temp -> data >= 10){
        temp -> data -= 10;
        temp = temp -> next;
    }

    *n = count;

    return start;
}

