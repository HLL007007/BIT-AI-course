# include <stdio.h>
int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    if (n < 1) return 0;
    for (int i = 1 ; i <= 2 * n - 1 ; i++){
        if (i <= n){
            for (int j = 1 ; j <= n + i - 1 ; j++){
                if(j >= n - i + 1 && j <= i + n - 1){
                    int num = 0;
                    if (j <= n) num = 2 * n + 1 - i - j;
                    else num = j - i + 1;
                    printf("%-2d", num);
                }
                else printf("  ");
            }
            printf("\n");
        }
        else{
            for (int j = 1; j <= 3 * n - i - 1; j++){
                if (j <= 3 * n - i - 1 && j >= i - n + 1){
                    int num = 0;
                    if (j <= n) num = i - j + 1;
                    else num = i + j - 2 * n + 1;       
                    printf("%-2d", num);
                } 
                else printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}