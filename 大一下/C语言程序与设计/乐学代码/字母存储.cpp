# include <stdio.h>
# include <stdlib.h>
typedef struct Node{
    char data;
    struct Node *next;
} Node;
int main(){
    char letters[] = {'a', 'b', 'c', 'd', 'c', 'b', 'a'};
    int len = 7;
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < len; i++){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = letters[i];
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }
        tail = newNode;
    }
    char c;
    scanf("%c", &c);
    if (c >= '0' && c <= '6'){
        int target_index = c - '0';
        int cnt = 0;
        Node *current = head;
        while (current != NULL && cnt < target_index){
            current = current->next;
            cnt++;
        }
        if (current != NULL){
            printf("%c\n", current->data);
        }
        else{
            printf("N\n");
        }
    }
    else if (c >= 'a' && c <= 'z'){
        Node *current = head;
        int index = 0;
        int ans = -1;
        while (current != NULL){
            if (current->data == c){
                ans = index;
            }
            current = current->next;
            index++;
        }
        if (ans != -1){
            printf("%d\n", ans);
        }
        else printf("N\n");
    }
    else printf("N\n");
    return 0;

}