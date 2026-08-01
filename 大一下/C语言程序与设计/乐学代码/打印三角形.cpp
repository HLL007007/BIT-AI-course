# include<stdio.h>
int main(){
    int n , m;
    if (scanf("%d %d",&n,&m) != 2) return 0;
    int a[m][m];
    int b[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
            b[i][j] = 0; 
        }
    }
    a[0][0] = n % 10;
    b[0][0] = 1;
    for (int j = 1; j < m; j++){
        a[0][j] = (a[0][j - 1] + 1) % 10;
        b[0][j] = 1;
    }
    for (int i = 1; i < m; i++){
        int k = m - 1 - i;
        a[i][k] = (a[i - 1][k + 1] + 1) % 10;
        b[i][k] = 1;
    }
    for (int i = m - 2; i > 0 ; i--){
        a[i][0] = (a[i + 1][0] + 1) % 10;
        b[i][0] = 1;
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m - i; j++){
            if (b[i][j] == 0){
                printf(" ");
            }
            else printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}