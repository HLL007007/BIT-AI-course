# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
int main(){
    int n;
    if ((scanf("%d",&n)) != 1) return 0;
    if (n < 2) return 0;
    while (n > 1){
        int i = 2;
        while (i <= n){
            if (n % i == 0){
                printf("%d\n",i);
                n = n / i;
                break;
            }
            i++;
        }      
    }
    return 0;
}