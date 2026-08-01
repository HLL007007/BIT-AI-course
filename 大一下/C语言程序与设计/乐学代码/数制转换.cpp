#include <stdio.h>
#include <string.h>

// 辅助函数：将字符转为对应的数值
int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return 0;
}

int main() {
    char str_m[50], str_n[50];
    // 以字符串形式读取，可以自动跳过空格并能读取字母
    if (scanf("%s %s", str_m, str_n) != 2) return 0;
    
    int a[50], b[50];
    // 初始化最大值为1，这样 max_num + 1 至少为 2（保证进制最小为2）
    int max_num_a = 1, max_num_b = 1; 
    
    int len_a = strlen(str_m);
    int len_b = strlen(str_n);

    // 将字符串 m 转换为数字数组，并找出最大位
    for (int i = 0; i < len_a; i++) {
        a[i] = charToInt(str_m[i]);
        if (a[i] > max_num_a) {
            max_num_a = a[i];
        }
    }

    // 将字符串 n 转换为数字数组，并找出最大位
    for (int i = 0; i < len_b; i++) {
        b[i] = charToInt(str_n[i]);
        if (b[i] > max_num_b) {
            max_num_b = b[i];
        }
    }

    // 双层循环枚举进制，i 是第一个数的进制，j 是第二个数的进制
    for (int i = max_num_a + 1; i <= 36; i++) {
        // 使用 long long 防止乘法过程溢出
        long long num_a = 0; 
        
        // 字符串是从左到右的(高位到低位)，所以直接从0遍历到len-1即可
        for (int k = 0; k < len_a; k++) {
            num_a = num_a * i + a[k];
        }

        for (int j = max_num_b + 1; j <= 36; j++) {
            long long num_b = 0;
            for (int k = 0; k < len_b; k++) {
                num_b = num_b * j + b[k];
            }

            if (num_a == num_b) {
                // 找到了相等的进制，直接打印原本的字符串
                printf("%s (base %d) = %s (base %d)\n", str_m, i, str_n, j);
                return 0;
            }
            // 你的原版优化保留：因为b的进制j在不断增大，num_b也会不断增大
            // 如果 num_b 已经大于 num_a 了，后面的 j 就不需要看了，直接 break
            else if (num_b > num_a) {
                break;
            }
        }
    }

    // 找不到的情况
    printf("%s is not equal to %s in any base 2..36\n", str_m, str_n);
    return 0;
}