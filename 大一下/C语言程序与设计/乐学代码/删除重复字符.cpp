# include <stdio.h>
# include <string.h>

int main(){
    char str[101] , ans[101];
    if (gets(str) == NULL) return 0;
    int len = strlen(str);
    int p = 1;
    ans[0] = str[0];
    for (int i = 1; i < len; i++){
        char ch = str[i];
        int flag = 0;
        for(int j = 0; j < p; j++){
            if (ans[j] == ch){
                flag = 1;
                break;
            }
        }
        if (flag == 0) ans[p++] = ch;
    }
    ans[p] = '\0';
    puts(ans);
    return 0;
}