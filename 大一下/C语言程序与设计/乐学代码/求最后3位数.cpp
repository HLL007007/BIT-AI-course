# include <stdio.h>
int main() {
    int num , pow;
    int ans = 1;
    scanf("%d %d", &num , &pow);
    if (pow == 0) printf("The last 3 numbers is 1.\n");
    else {
        int p = 0;
        for (int i = 1; i <= pow; i++) {
            ans *= num;
            if (ans >= 1000) {
                ans = ans % 1000;
                p = 1;
            }
        }
        if (p == 0) printf("The last 3 numbers is %d.\n", ans);
        else printf("The last 3 numbers is %03d.\n", ans);
    }
    return 0;
}