# include <stdio.h>

int circle(int n, int m){
    if (n == 1) return 0;
    else return (circle(n-1, m) + m) % n;
}
int main(){
    int n , m;
    if (scanf("%d %d",&n,&m) != 2) return 0;
    int ans = circle(n,m) + 1;
    printf("The left child is NO %d.\n",ans);
    return 0;
}