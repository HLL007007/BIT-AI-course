#include <stdio.h>

void output(int n, int w, int h) {
    // 计算冰激凌的最宽处宽度 (最后一层的宽度)
    int max_w = w + 4 * (n - 1);
    // 计算中心轴的位置（前面需要补的空格数最大值）
    int center = max_w / 2;
    int i , j , k;
    // 1. 画冰激凌头部 (固定两行)
    // 第一行: 1个星号
    for (i = 0; i < center; i++) {
        printf(" ");
    }
    printf("*\n");
    
    // 第二行: 3个星号
    for (i = 0; i < center - 1; i++) {
        printf(" ");
    }
    printf("***\n");

    // 2. 画矩形冰激凌层
    for (i = 0; i < n; i++) {
        // 当前层的宽度
        int cur_w = w + 4 * i;
        // 当前层左侧需要填充的空格数
        int spaces = (max_w - cur_w) / 2;
        
        // 每一层有 h 行
        for (k = 0; k < h; k++) {
            // 打印左侧空格
            for (j = 0; j < spaces; j++) {
                printf(" ");
            }
            // 打印星号
            for (j = 0; j < cur_w; j++) {
                printf("*");
            }
            printf("\n"); // 换行
        }
    }

    // 3. 画空心甜筒
    int outer_spaces = 0;               // 甜筒外侧(左侧)的空格数
    int inner_spaces = max_w - 2;       // 甜筒内部的空格数

    // 当内部还能放下空格时，说明还没到最底部的尖端
    while (inner_spaces > 0) {
        // 打印外侧空格
        for (i = 0; i < outer_spaces; i++) {
            printf(" ");
        }
        printf("*"); // 左侧甜筒边
        
        // 打印内侧空格
        for (i = 0; i < inner_spaces; i++) {
            printf(" ");
        }
        printf("*\n"); // 右侧甜筒边并换行
        
        outer_spaces++;       // 下一行外侧空格多1个
        inner_spaces -= 2;    // 下一行内侧空格少2个 (左右各往里缩进1个)
    }

    // 画甜筒最底部的尖端 (只有1个星号)
    for (i = 0; i < outer_spaces; i++) {
        printf(" ");
    }
    printf("*\n");
}

int main() {
    int n, w, h;
    // 读取输入
    if (scanf("%d %d %d", &n, &w, &h) == 3) {
        output(n, w, h);
    }
    return 0;
}
