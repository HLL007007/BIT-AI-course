//字符串练习 05：输入字符串 s 和 t。计算子串 t 在字符串 s 中连续出现的最多次数
//例如：abcxabcabc 和 abc， abc 连续出现 2 次 

# include <stdio.h>
# include <string.h>
# define N 100

int main(){
    char s[N] , t[N];
    scanf("%s%s",s,t);
    int k = 0 , i , j;
    int maxc = 0 ; int cnt = 0;
    while (s[k]){
        i = k;
        j = 0;
        while(s[i]&&t[j]&&s[i] == t[j]) {i++;j++;}
        // 下面是寻找退出条件
        if (t[j] == '\0'){//出现字串t
            cnt ++;
            if (cnt > maxc) maxc = cnt;
        }
        if (s[i] == '\0') break;
        // 成功情况
        else if (t[j] == '\0') k = i;
        // 失败情况
        else{k++;cnt = 0;}
    }
    printf("%d\n", maxc);
    return 0;
}

