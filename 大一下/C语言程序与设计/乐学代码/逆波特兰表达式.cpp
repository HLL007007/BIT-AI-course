# include <stdio.h>

int main(){
    char ch;
    int pool[10000];
    int pool_idx = 0, innumber = 0;
    int num = 0;
    while ((ch = getchar()) != EOF && ch != '\n'){
        if (ch >= '0' && ch <= '9'){
            innumber = 1;
            num = num * 10 + ch - '0';
        }
        else if (innumber){
            pool[pool_idx++] = num;
            innumber = 0;
            num = 0;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if (pool_idx < 2) continue;
            int opnum2 = pool[--pool_idx];
            int opnum1 = pool[--pool_idx];
            switch(ch){
                case '+': pool[pool_idx++] = opnum1 + opnum2; break;
                case '-': pool[pool_idx++] = opnum1 - opnum2; break;
                case '*': pool[pool_idx++] = opnum1 * opnum2; break;
                case '/': pool[pool_idx++] = opnum1 / opnum2; break;
            }
        }
        else continue;
    }
    printf("%d\n", pool[0]);
    return 0;
}