# include <stdio.h>

int total(int v,int rest,int sells[]){
    if (v == 1) {
        sells[v] = rest + 2;
        return ((rest + 1) * 2);
    }
    else{
        sells[v] = rest + 2;
        return total(v - 1, (rest + 1) * 2, sells);
    }
}

int main(){
    int sells[8] = {0};
    int result = total(7, 2, sells);
    printf("sum=%d\n", result);
    for (int i = 1; i <= 7; i++) {
        printf("sell=%d,", sells[i]);
    }
    printf("\n");
    return 0;
}