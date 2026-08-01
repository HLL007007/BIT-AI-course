# include <stdio.h>
# include <string.h>
# define N 10000
int main(){
    char s[N] , t[N] , u[N];
    int p = 0;
    if (gets(s) == NULL) return 0;
    if (gets(t) == NULL) return 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    for (int i = 0; i < len_s; i++){
        char ch = s[i];
        int found = 0;
        for (int j = 0; j < len_t; j++){
            if (ch == t[j]) {found = 1; break;}
        }
        if (!found) u[p++] = ch;
    }
    u[p] = '\0';
    printf("%s\n", u);
    return 0;
}