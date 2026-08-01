# include <stdio.h>

int main(){
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    char a[n][2 * n - 1];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2 * n - 1; j++){
            a[i][j] = ' ';
        }
    }
    char current = ch;
    for (int i = 0; i < n; i++){
        a[i][n - 1 - i] = current;
        if (current == 'Z'){
            current = 'A';
        }
        else{
            current++;
        }
    }
    for (int j = 1; j < 2 * n - 2; j++){
        a[n - 1][j] = current;
        if (current == 'Z'){
            current = 'A';
        }
        else{
            current++;
        }
    }
    for (int i = n - 1; i >= 1; i--){
        a[i][n - 1 + i] = current;
        if (current == 'Z'){
            current = 'A';
        }
        else{
            current++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + i; j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}