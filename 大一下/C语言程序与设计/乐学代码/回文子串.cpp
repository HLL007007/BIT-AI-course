//字符串练习 04：输入一个连续非分隔字符单词，查找一个字符串中最大长度回文子串（可包含自己）
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# define N 100
int main(){
    char s[N];
    int i , j , len_s;
    scanf("%s",s);
    len_s = strlen(s);
    for (int w = len_s;w > 1;w--){//枚举字串长度
        for (int x = 0;x + w - 1 < len_s ;x++){
            int y = x + w - 1; 
            // 字串为 x ~ y
            i = x; j = y;
            while(i <= j && s[i] == s[j]){
                i++; j--;
            }
            if (i >=j){
                // 找到最长回文串
                for (int t = x ; t <= y ; t ++){
                    putchar(s[t]);
                }
                putchar('\n');
                return 0;
            }
        }
    }
    return 0;
}