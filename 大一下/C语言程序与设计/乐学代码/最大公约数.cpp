// 用递归方法来求最大公约数gcd(n,m)
# include <stdio.h>
int gcd(int n, int m){
    if (m == 0) return n;
    else return gcd(m,n %m);
}

int main(){
    int n , m;
    if (scanf("%d %d",&n,&m) != 2) return 0;
    printf("gcd = %d",gcd(n,m));
    return 0;
}