# include <stdio.h>

int jumpFloor(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    else return jumpFloor(n-1) + jumpFloor(n-2);
}
int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d",jumpFloor(n));
    return 0;
}