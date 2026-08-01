# include <stdio.h>

int main(){
    char c;
    if (scanf("%c", &c) != 1) return 0;
    if (c < '0'|| c > '9') {
        printf("input error\n");
        return 0;
    }
    int n = c - '0';
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 2*n - i;j++){
            if (j == i || j == 2*n - i) printf("%d",i);
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = n + 1; i <= 2*n - 1;i++){
        for (int j = 1; j <= i;j++){
            int num = i;
            if (num > 9) num = num - 9;
            if (j == i|| j == 2*n - i)printf("%d",num);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}