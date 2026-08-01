# include <stdio.h>
int main(){
    int num;
    int i = 1;
    int ans = 0;
    scanf("%d",&num);
    while(ans < num){
        ans += i;
        i++;
    }
    printf("%d\n", i - 1);
    return 0;
}