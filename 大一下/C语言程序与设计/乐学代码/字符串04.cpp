# include <stdio.h>
# include <string.h>
# include <stdlib.h>
int check_modify(char *a, char *b,int len){
    int diff_count = 0;
    for (int i = 0; i < len; i++){
        if (a[i] != b[i]){
            diff_count++;
        if (diff_count > 1) return 0;
        }
    }
    return diff_count == 1;
}

int check_insert_delete(char *shorter, char *longer, int len_s, int len_l){
    int i = 0;
    int j = 0;
    int diff_count = 0;
    while (i < len_s && j < len_l){
        if (shorter[i] == longer[j]){
            i++;
            j++;
        }
        else{
            diff_count++;
            if (diff_count > 1) return 0;
            j++;
        }
    }
    return 1;
}
void process_test_case(){
    char A[60];
    char B[60];
    scanf("%s %s", A, B);

    int len_a = strlen(A);
    int len_b = strlen(B);
    if (strcmp(A, B) == 0){
        printf("Right\n");
        return;
    }
    if (len_a == len_b){
        if (check_modify(A, B, len_a)){
            printf("Pass\n");
        }
        else{
            printf("Fail\n");
        }
    }
    else if (len_a - len_b == 1){
        if (check_insert_delete(B, A, len_b, len_a)){
            printf("Pass\n");
        }
        else{
            printf("Fail\n");
        }
    }
    else if (len_b - len_a == 1){
        if (check_insert_delete(A, B, len_a, len_b)){
            printf("Pass\n");
        }
        else{
            printf("Fail\n");
        }
    }
    else{
        printf("Fail\n");
    }
}
int main(){
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while(t){
        process_test_case();
        t--;
    }
    return 0;
}