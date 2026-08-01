# include <stdio.h>

int main(){
    int a[10];
    if (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8]) != 9) {
        return 1;
    }
    if (scanf("%d,%d", &a[9]) != 1) {
        return 1;
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9 - i; j++){
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 9; i++){
        printf("%d,", a[i]);
    }
    printf("%d\n", a[9]);
    return 0;
}