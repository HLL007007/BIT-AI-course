# include <stdio.h>

int f(int m ,int n);

int main(){
    int m , n;
    if (scanf("%d %d",&m,&n) != 2) return 0;
    int sum = f(m , n);
    printf("%d\n",sum);
    return 0;
}

int f(int m, int n){
    if (m == 1 || n == 1) return 1;
    if (m < n) return f(m , m);
    if (m == n) return 1 + f(m , n - 1);
    if (m > n) return f(m - n , n) + f(m , n - 1);
}