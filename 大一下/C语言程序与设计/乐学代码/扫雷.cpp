# include <stdio.h>

int main(){
    int n , m , cnt = 1;
    while ((scanf("%d %d",&n,&m) == 2)){
        if (n == 0 || m == 0) break;
        char map[105][105];
        for (int i = 0; i < n; i++){
            scanf("%s",map[i]);
        }
        if (cnt > 1) printf("\n");
        printf("Field #%d:\n",cnt++);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (map[i][j] == '*'){
                    putchar('*');
                }
                else{
                    int sum = 0;
                    for (int r = i - 1;r <= i + 1; r++){
                        for (int k = j - 1; k <= j + 1; k++){
                            if (r >= 0 && r < n && k >= 0 && k < m && map[r][k] == '*') sum++;
                        }
                    }
                    printf("%d",sum);
                }
            }
            printf("\n");
        }
    }
    return 0;
}