# include <stdio.h>
int main(){
    int n;
    if (scanf("%d",&n) != 1){
        return 0;
    }
    if(n < 1) return 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int s , base , offset;
            s = i + j;
            if(s < n) {
                base = (s + 1) * s / 2;
                if (s % 2 == 0) offset = j + 1;
                else offset = i + 1;
            }
            else {
                base = n * n - (2 * n - s - 1) * (2 * n - s) / 2;
                if (s % 2 == 0) offset = j - s + n;
                else offset = i - s + n;
            }
            printf("%2d", base + offset);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
