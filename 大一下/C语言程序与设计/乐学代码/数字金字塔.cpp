# include <stdio.h>
int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    if (n < 1) return 0;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n + i - 1 ; j++){
            if (j >= n - i + 1 && j <= n + i - 1){
                int num;
                if (j <= n) num = j - n + i;
                else num = i - (j - n);
                printf("%2d",num);
            }
            else printf("  ");
        }
        printf("\n");
    }
    return 0;
}