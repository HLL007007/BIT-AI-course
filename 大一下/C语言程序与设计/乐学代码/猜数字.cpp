#include <stdio.h>

int main() {
    int row;
    int res = 0;
    while (1) {
        scanf("%d", &row);
        if (row == 0) {
            break;
        }
        res += (1 << (row - 1));
    }
    printf("%d\n", res);
    return 0;
}