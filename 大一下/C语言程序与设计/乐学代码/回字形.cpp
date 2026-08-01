# include <stdio.h>
int min4(int a, int b, int c, int d) {
    int m1 = (a < b) ? a : b;
    int m2 = (c < d) ? c : d;
    return (m1 < m2) ? m1 : m2;
}
int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int l = min4(i, j, n - 1 - i, n - 1 - j);
            int s = n - 2 * l;
            int base = n * n - s * s;
            int offset;
            if(i == l) offset = j - l;
            else if (j == n - 1 - l) offset = s - 1 + i - l;
            else if (i == n - 1 - l) offset = 2 * (s - 1) + n - 1 - l - j;
            else offset = 3 * (s - 1) + n - 1 - l - i;
            int num = base + offset + 1;
            printf("%3d", num);
        }
        printf("\n");   
    }
    return 0;
}