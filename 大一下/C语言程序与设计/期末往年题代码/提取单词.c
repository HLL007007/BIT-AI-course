/* 字符串练习 03：提取单词，输入一段由字母、数字、等 ascii 有效字符组成的文字，
请提取出仅由连续字母组成单词并输出(win 按 ctrl+z 结束,linux 按 ctrl+结束，乐学系统文件尾自动)。*/

# include <stdio.h>
# include <string.h>
#include <ctype.h>
# define N 100
int main(){
    char ch , word[N] , t = 0 , inword = 0;
    while((ch = getchar())!= EOF && ch != '\n'){
        if (isalpha(ch)){
            word[t++] = ch;
            inword = 1;
        }
        else if (inword){
            inword = 0;
            word[t] = '\0';
            puts(word);
            t = 0;
        }
    }
    if (inword){
        word[t] = '\0';
        puts(word);
    }
}