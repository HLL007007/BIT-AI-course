# include <stdio.h>
# include <string.h>
void check(char s[],int l , int r);

int main(){
    char s[100];
    if (scanf("%s",s) != 1) {
        printf("Yes\n");
        return 0;
    }
    int n = strlen(s);
    if (n == 1 || n == 0){
        printf("Yes\n");
        return 0;
    }
    int l = 0;
    int r = n - 1;
    check(s, l , r);
    return 0;
}

void check(char s[] , int l , int r){
    if (l >= r) {
        printf("Yes\n");
        return;
    }
    if (s[l] != s[r]){
        printf("No\n");
        return;
    }
    check(s , l + 1 , r - 1);
}