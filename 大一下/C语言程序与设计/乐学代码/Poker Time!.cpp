#include <stdio.h>
#include <string.h>

// 定义扑克牌结构体
typedef struct {
    char suit;          // 花色字符
    int suit_val;       // 花色权重 (H=4, S=3, D=2, C=1)
    int rank_val;       // 大小权重 (2~14)
    char original[4];   // 原始输入的字符串 (如 "H2", "D10")
} Card;

// 解析并验证卡牌字符串，如果合法则存入结构体，返回1；否则返回0
int parse_card(const char* str, Card* c) {
    int len = strlen(str);
    if (len < 2 || len > 3) return 0; // 长度不符

    // 解析花色
    c->suit = str[0];
    switch(c->suit) {
        case 'H': c->suit_val = 4; break;
        case 'S': c->suit_val = 3; break;
        case 'D': c->suit_val = 2; break;
        case 'C': c->suit_val = 1; break;
        default: return 0; // 错误的花色
    }

    // 解析大小
    if (len == 2) {
        char r = str[1];
        if (r >= '2' && r <= '9') c->rank_val = r - '0';
        else if (r == 'J') c->rank_val = 11;
        else if (r == 'Q') c->rank_val = 12;
        else if (r == 'K') c->rank_val = 13;
        else if (r == 'A') c->rank_val = 14;
        else return 0; // 错误的大小字符
    } else if (len == 3) {
        if (str[1] == '1' && str[2] == '0') c->rank_val = 10;
        else return 0; // 错误的大小字符
    }
    
    strcpy(c->original, str);
    return 1;
}

// 比较两张牌大小。 c1 > c2 返回正数， c1 < c2 返回负数， 相等返回0
int compare_cards(Card c1, Card c2) {
    if (c1.suit_val != c2.suit_val) {
        return c1.suit_val - c2.suit_val; // 先比花色
    }
    return c1.rank_val - c2.rank_val;     // 再比大小
}

// 对三张牌进行降序排序 (冒泡法)
void sort_hand(Card hand[3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (compare_cards(hand[i], hand[j]) < 0) { // 如果后面的牌比前面的牌大，则交换
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// 检查同一副手牌里是否有重复牌
int has_duplicates(Card hand[3]) {
    if (compare_cards(hand[0], hand[1]) == 0) return 1;
    if (compare_cards(hand[1], hand[2]) == 0) return 1;
    if (compare_cards(hand[0], hand[2]) == 0) return 1;
    return 0;
}

int main() {
    char bufA[3][10];
    char bufB[3][10];

    // 读取输入数据
    if (scanf("%s %s %s", bufA[0], bufA[1], bufA[2]) != 3) return 0;
    if (scanf("%s %s %s", bufB[0], bufB[1], bufB[2]) != 3) return 0;

    Card A[3], B[3];

    // 解析A和B的牌，并做格式检查
    for (int i = 0; i < 3; i++) {
        if (!parse_card(bufA[i], &A[i]) || !parse_card(bufB[i], &B[i])) {
            printf("Input Error!\n");
            return 0;
        }
    }

    // 判断A和B各自手牌中是否有重复出现的牌（不可能自己抽到两张一模一样的牌）
    if (has_duplicates(A) || has_duplicates(B)) {
        printf("Input Error!\n");
        return 0;
    }

    // 排序
    sort_hand(A);
    sort_hand(B);

    // 比较胜负
    char winner = 'X';
    for (int i = 0; i < 3; i++) {
        int cmp = compare_cards(A[i], B[i]);
        if (cmp > 0) { 
            winner = 'A'; 
            break; 
        }
        if (cmp < 0) { 
            winner = 'B'; 
            break; 
        }
    }

    // 打印输出
    printf("Winner is %c!\n", winner);
    printf("A: %s %s %s\n", A[0].original, A[1].original, A[2].original);
    printf("B: %s %s %s\n", B[0].original, B[1].original, B[2].original);

    return 0;
}