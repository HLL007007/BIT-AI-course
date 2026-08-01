# include <stdio.h>

int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    if (n < 3 || n > 19 || n % 2 != 1) return 0;
    char c = 'X';
    char a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++){
        a[i][i] = c;
        a[i][n - i - 1] = c;
    }
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n - i; j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    for (int i = n/2 ; i < n; i++){
        for (int j = 0; j < i + 1; j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}