//小明手中有硬币，小红手中有若干张10元的纸币。
//已知 1 角硬币厚 1.8mm，5 角硬币厚 1.5mm，1 元硬币厚 2.0mm 。
//小红拿出若干张10元的纸币，小明要将 1 角的硬币放成一摞，将 5 角的硬币放成一摞，将 1 元的硬币放成一摞，
//如果 3 摞硬币一样高，且三摞硬币的金额之和正好等于小红要求的面值，则双方交换，否则没有办法交换。

# include <stdio.h>
int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    if(n < 1) return 0;
    int money = 10 * n;
    if (money % 16 != 0) {
        printf("No change.\n");
        return 0;
    }
    int m = money / 16;
    printf("%d,%d,%d\n",m*10,m*12,m*9);
    return 0;
}