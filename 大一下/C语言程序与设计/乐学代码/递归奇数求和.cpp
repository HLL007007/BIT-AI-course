# include <stdio.h>

int sum(int n){
    if (n == 1) return 1;
    return (2 * n - 1) + sum(n - 1);
}
int main(){
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    printf("%d\n", sum(n));
    return 0;
}