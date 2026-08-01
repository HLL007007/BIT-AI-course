# include <stdio.h>
int n , v;
int w[25] ;
long long p[25];
long long max(long long a, long long b){
    return a > b ? a : b;
}
long long bag(int n, int v){
    if (n <= 0) return 0;

    long long not_include = bag(n - 1, v);
    long long include = 0;
    if (v >= w[n]){
        include =  bag(n - 1, v - w[n]) + p[n];
    }
    return max(not_include, include); 
}
int main(){
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++){
        scanf("%d %lld", &w[i], &p[i]);
    }
    long long ans = bag(n, v);
    printf("%lld\n", ans);
    return 0;
}