# include <stdio.h>

int main(){
    int op , n;
    int nums[10000];
    int ans[10000];
    if (scanf("%d",&op) != 1) return 0;
    if (scanf("%d",&n) != 1) return 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&nums[i]);
    }
    if (op != 1 && op != 2) return 0;
    if (n < 1 || n > 10000) return 0;
    if (op == 1){
        ans[0] = 0;
        for (int i = 1; i < n; i++){
            int res = 0;
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]) res++;
            }
            ans[i] = res;
        }
    }
    else{
        int pool[n];
        for (int i = 0; i < n; i++) {
        pool[i] = i;
        }
        int pool_size = n;
        for (int i = n - 1; i >= 0; i--){
            int count = nums[i];
            ans[i] = pool[count];
            for (int j = count; j < pool_size - 1; j++) {
                pool[j] = pool[j + 1];
            }
        pool_size--;
        }
    }
    for (int i = 0; i < n - 1; i++){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[n-1]);
    return 0;
}