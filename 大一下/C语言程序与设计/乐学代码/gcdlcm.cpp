# include <stdio.h>
int fun1(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int fun2(int a, int b) {
    return a / fun1(a, b) * b;
}
int main(){
    int a, b;
    if (scanf("%d,%d", &a, &b) != 2) {
        return 0;
    }
    printf("最大公约数：%d\n", fun1(a, b));
    printf("最小公倍数：%d\n", fun2(a, b));
    return 0;
}