# include <stdio.h>
# include <string.h>
int check(int l, int r,char str[]){
    while (l < r){
        if (str[l] == str[r]){
            l++;
            r--;
        }
        else{
            return 0;
        }
    }
    if (l >= r) return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char s[105];
        gets(s);
        int n = strlen(s);
        if (n < 4){
            printf("No\n");
            continue;
        }
        int l1, l2, r1, r2;
        l1 = 0; 
        r2 = n - 1;
        int flag = 0;
        for (int i = 1; i < n - 1;i++){
            l2 = i;
            r1 = i + 1;
            if (check(l1,l2,s) && check(r1,r2,s)){
                flag = 1;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}