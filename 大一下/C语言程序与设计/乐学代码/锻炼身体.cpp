# include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int c = 1; c <= n ; c++){
        for (int a = 1; a < c; a++){
            for (int b = a; b < c; b++){
                    if (a*a + b*b == c*c){
                    ans++;
            }
        }
    }
    }    
    printf("%d\n", ans);
    return 0;
}