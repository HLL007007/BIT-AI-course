# include <stdio.h>
int f(int m){
    if (m == 1 || m == 0) return 0;
    if (m % 2 == 1) return m;
    else return m - 1;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int cnt;
        scanf("%d",&cnt);
        printf("%d\n",f(cnt));
    }
    return 0;
}