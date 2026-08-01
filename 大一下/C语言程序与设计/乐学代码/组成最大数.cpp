# include<stdio.h>
# include<string.h>
# define N 100000

int main(){
    char num[N];
    if (scanf("%s",num) != 1) return 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (num[j] < num[j + 1]){
                char temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    num[len] = '\0';
    printf("%s\n",num);
    return 0;
}