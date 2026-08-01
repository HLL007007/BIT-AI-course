# include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n > 1){
        printf("%d,", n);
        if (n % 2 == 0){
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        ans++;
    }
    printf("1\n");
    printf("step=%d\n", ans + 1);
    return 0;
}