# include <stdio.h>

int main(){
    int scores[12];
    for(int i = 0; i < 12; i++){
        scanf("%d", &scores[i]);
    }
    int p;
    double sum = 0;
    scanf("%d", &p);
    for (int i = 4 * (p - 1); i < 4 * p; i++) {
        if (i < 4 * p - 1) {
            printf("%d ", scores[i]);
        }
        else {
            printf("%d\n", scores[i]);
        }
        sum += scores[i];
    }
    printf("%.2f\n", sum / 4);
    return 0;
}