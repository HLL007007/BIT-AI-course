# include <stdio.h>

void puta(int a[],int n){
    if (n % 2 == 0){
        for(int i = 0; i < n/2; i++){
            int ans = a[i] * a[n - 1 - i];
            printf("%d ", ans);
        }
    }
    else{
        for (int i = 0; i < n/2; i++){
            int ans = a[i] * a[n - 1 - i];
            printf("%d ", ans);
        }
        printf("%d ", a[n/2]);
    }
    printf("\n");
}

int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[n];
    for (int i = 0; i < n; i++){
        if (scanf("%d", &a[i]) != 1) return 0;
    }
    puta(a, n);
    return 0;
}