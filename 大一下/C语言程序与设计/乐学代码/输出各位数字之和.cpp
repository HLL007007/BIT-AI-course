# include <stdio.h>
int sum(int n){
    if (n == 0) return 0;
    return n % 10 + sum(n / 10);
}
int main(){
    int n;
    if(scanf("%d", &n) != 1) return 1;
    printf("%d\n", sum(n));
    return 0;
}