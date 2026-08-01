# include <stdio.h>
# include <string.h>
int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    if (n <= 0) return 0;
    getchar();
    for (int k = 0; k < n; k++){
        char s[100];
        gets(s);
        int len = strlen(s);
        if (len < 6){
            printf("Not Safe\n");
            continue;
        }
        int flag[4] = {0 , 0, 0, 0};
        for (int i = 0; i < len; i++){
            if (s[i] >= 'a' && s[i] <= 'z') flag[0] = 1;
            else if (s[i] >= 'A' && s[i] <= 'Z') flag[1] = 1;
            else if (s[i] >= '0' && s[i] <= '9') flag[2] = 1;
            else flag[3] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < 4; i++){
            cnt += flag[i];        
        }
        if (cnt <= 1){
            printf("Not Safe\n");
            continue;
        }
        else if (cnt == 2){
            printf("Medium Safe\n");
            continue;
        }
        else {
            printf("Safe\n");
            continue;
        }
    }
    return 0;
}