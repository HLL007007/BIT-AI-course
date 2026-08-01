# include <stdio.h>

int check (int n1 , int n2, int n3){
    if (n2 > 999 || n3 > 999) return 0;

    int vis[10] = {0};
    int nums[3] = {n1 , n2 , n3};
    for (int i = 0; i < 3; i++){
        int num = nums[i];
        while (num){
            int digit = num % 10;
            if (digit == 0 || vis[digit]) return 0;
            vis[digit] = 1;
            num /= 10;
        }
    }
    for (int i = 1; i <= 9; i++){
        if (!vis[i]) return 0;
    }
    return 1;
}

int main(){
    int first_digit;
    int found = 0;
    if (scanf("%d",&first_digit)!= 1) return 0;
    for (int i = 100 * first_digit; i < 100 * (first_digit + 1);i++){
        if (i < 123) continue;
        int n1 = i;
        int n2 = 2 * n1;
        int n3 = 3 * n1;
        if (check(n1,n2,n3)) {printf("%d,%d,%d\n",n1,n2,n3);found = 1;}
    }
    if (!found) printf("0,0,0\n");
    return 0;
}