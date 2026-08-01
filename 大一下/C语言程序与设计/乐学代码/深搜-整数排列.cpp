# include <stdio.h>
# define N 100
int a[N];
int vis[N] = {0};
void puta(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void f(int n,int i){
    if (i > n){
        puta(n);
        return;
    }
    for (int j = 1; j <= n; j++){
        if (vis[j] == 0){
            a[i] = j;
            vis[j] = 1;
            f(n, i + 1);
            vis[j] = 0;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    f(n, 1);
    return 0;
}