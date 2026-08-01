# include <stdio.h>
int main(){
    int n;
	char ch;
	if (scanf("%c,%d",&ch,&n) != 2) return 0;
    int ch_ascii = ch;
    if (ch_ascii < 65 || ch_ascii > 90) return 0;
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n + i - 1; j++){
            if (j == n + i - 1 || j == n - i + 1){
                int num = ch_ascii + (i - 1);
                while (num > 90) {num -= 26;}
                printf("%c", num);
            }
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 2 * n -i; j++){
            if (j == i || j == 2 *n - i){
                int num = ch_ascii + (n -i);
                while (num > 90) {num -= 26;}
                printf("%c", num);
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}