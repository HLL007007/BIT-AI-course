# include <stdio.h>
#include <ctype.h>

char output(char ch, int shift){
    ch = toupper(ch);
    return (ch - 'A' + shift) % 26 + 'A';
}
int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    if (n < 1 || !isalpha(c)) return 0;
    if (n == 1){
        printf("%c", output(c, 0));
        printf("\n");
        return 0;
    }
    char a[2 * n - 1][2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++){
        for (int j = 0; j < 2 * n - 1; j++){
            a[i][j] = ' ';
        }
    }
    for (int i = 0; i < n - 1; i++){
        a[i][n - 1 -i] = output(c, i);
    }
    for (int i = n - 1; i < 2 * n - 2; i++){
        a[i][i - n + 1] = output(c,i);
    }
    for (int i = 2 * n - 2; i > n - 1; i--){
        a[i][3 * n - 3 - i] = output(c,2 * n - 2 + (2 * n - 2 - i));
    }
    for (int i = n - 1; i > 0; i--){
        a[i][n - 1 + i] = output(c,2 * n - 2 + (2 * n - 2 - i));
    }
    for (int i = 0; i <= n - 1; i++){
        for (int j = 0; j < i + n; j++){
            printf("%c", a[i][j]); 
        }
        printf("\n"); 
    }
    for (int i = n; i <= 2 * n - 2; i++){
        for (int j = 0; j < 3 * n - 2 - i; j++){
            printf("%c", a[i][j]); 
        } 
        printf("\n"); 
    }
    return 0;
}