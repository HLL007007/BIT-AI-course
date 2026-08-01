# include <stdio.h>

char x(char c,int n){
    char res;
    if (c + n > 'Z') res = c + n - 26;
    else if (c + n < 'A') res = c + n + 26;
    else res = c + n;
    return res;
}
int main(){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    if (n < 1) return 0;
    if (c < 'A' || c > 'Z') {
        printf("input error.\n");
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 2 * n - i; j++){
            if (j == i || j == 2 * n - i) printf("%c",x(c,n - i));
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n + i; j++){
            if (j == i + n || j == n - i) printf("%c",x(c,-i));
            else printf(" ");
        }
        printf("\n");
    }
    return 0;

}