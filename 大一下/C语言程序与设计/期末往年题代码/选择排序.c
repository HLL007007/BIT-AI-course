// 从大到小选择排序
# include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int temp;
    int k;
    for (int i = 0; i < n - 1; i++){
        k = i;
        for (int j = i; j < n; j++){
            if (a[j] < a[k]) k = j;
        }
        if (k != i){
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}