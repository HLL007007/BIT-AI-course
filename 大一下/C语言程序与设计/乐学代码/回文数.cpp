# include <stdio.h>
int check(int num){
    int origin = num, reverse = 0;
    while(num){
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return origin == reverse;
}

int main(){
    int n;
    if (scanf("%d", &n)!= 1) return 0;
    if (n < 1 || n >= 256) return 0;
    for (int i = 1; i < n; i++){
        if (check(i) && check(i * i)) printf("%d\n", i);
        else continue;
    }
    return 0;
}