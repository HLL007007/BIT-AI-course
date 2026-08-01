# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define N 100
typedef struct Node{
    char data;
    struct Node *next;
} Node;

Node* createNode(char data);
Node* readList();
Node* mergeLists(Node* l1, Node* l2);
void printList(Node* head);
void freeList(Node* head);

int main(){
    Node* list1 = readList();
    Node* list2 = readList();
    Node* mergedList = mergeLists(list1, list2);
    printList(mergedList);
    freeList(mergedList);
    return 0;
}

Node* createNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* readList(){
    Node *head = NULL , *tail = NULL;
    char c;
    while((c = getchar()) != '\n' && c != EOF){
        if (isalpha(c)){
            Node* newNode = createNode(c);
            if (head == NULL){
                head = newNode;
            }
            else{
                tail->next = newNode;
            }
            tail = newNode;
        }
    }
    return head;
}

Node* mergeLists(Node* l1, Node* l2){
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;
    while (l1 != NULL && l2 != NULL){
        Node* temp = NULL;
        if (l1->data < l2->data){
            temp = l1;
            l1 = l1->next;
        }
        else if (l2->data < l1->data){
            temp = l2;
            l2 = l2->next;
        }
        else{
            temp = l1;
            l1 = l1->next;
            Node* duplicate = l2;
            l2 = l2->next;
            free(duplicate);
        }
        if (tail != &dummy && tail->data == temp->data) {
            free(temp);
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    Node* remain = (l1 != NULL) ? l1 : l2;
    while (remain != NULL) {
        Node* temp = remain;
        remain = remain->next;
        if (tail != &dummy && tail->data == temp->data) {
            free(temp);
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    tail->next = NULL;
    return dummy.next;
}

void printList(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("%c", current->data);
        if (current->next != NULL){
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* head){
    Node* current = head;
    while (current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}