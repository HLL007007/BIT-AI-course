# include <stdio.h>
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n , m;
    if (scanf("%d %d",&n,&m) != 2) return 0;
    if (n < 1 || m < 1 || n > 100 || m > 100) return 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d",&a[i]) != 1) return 0;
    }
    int bit[m];
    for (int i = 0; i < m; i++){
        if (scanf("%d",&bit[i]) != 1) return 0;
    }
    if (n > m) {
        printf("bit is doomed!\n");
        return 0;
    }
    sort(a,n);
    sort(bit,m);
    int ans = 0;
    int p =0;
    for (int i = 0; i < n; i++){
        while(p < m && a[i] > bit[p]){
            p++;
        }
        if (p >= m){
            printf("bit is doomed!\n");
            return 0;
        }
        ans += bit[p++];
    }
    printf("%d\n",ans);
    return 0;
}