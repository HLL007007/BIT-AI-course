# include <stdio.h>

int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a , b;
    if (scanf("%d,%d", &a, &b) != 2) {
        return 0;
    }
    printf("%d\n", gcd(a, b));
    return 0;
}