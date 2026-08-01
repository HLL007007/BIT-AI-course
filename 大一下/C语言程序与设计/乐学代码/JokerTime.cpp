# include <stdio.h>
# include <string.h>

int card(char str[]){
    int len = strlen(str);
    if (len < 2 || len > 3) return -1;

    int color = 0;
    switch(str[0]){
        case 'H' : color = 4; break;
        case 'S' : color = 3; break;
        case 'D' : color = 2; break;
        case 'C' : color = 1; break;
        default : return -1;
    }
    int num = 0;
    switch (str[1]) {
        case '2': num = 2; break;
        case '3': num = 3; break;
        case '4': num = 4; break;
        case '5': num = 5; break;
        case '6': num = 6; break;
        case '7': num = 7; break;
        case '8': num = 8; break;
        case '9': num = 9; break;
        case 'J': num = 11; break;
        case 'Q': num = 12; break;
        case 'K': num = 13; break;
        case 'A': num = 14; break;
        
        // 特殊处理 10 的情况
        case '1': 
            if (str[2] == '0' && str[3] == '\0') num = 10;
            else return -1; 
            break;
        default: return -1; 
    }
    if (str[1] != '1' && str[2] != '\0') return -1;
    return color * 100 + num;
}

void sort(char str[3][16],int val[3]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 - i; j++){
            if (val[j] < val[j + 1]){
                char temp_str[16];
                int temp_val;
                // 交换字符串
                strcpy(temp_str, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp_str);
                // 交换对应的数值
                temp_val = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp_val;
            }
        }
    }
}

int check(int val[3]){
    if(val[0] == val[1] || val[1] == val[2] || val[0] == val[2]) return 1;
    return 0;
}

int main(){
    char A_str[3][16] ,B_str[3][16];
    int A_val[3] ,B_val[3];
    if (scanf("%s %s %s",A_str[0],A_str[1],A_str[2]) != 3) return 0;
    if (scanf("%s %s %s",B_str[0],B_str[1],B_str[2]) != 3) return 0;
    for (int i = 0; i < 3; i++){
        A_val[i] = card(A_str[i]);
        B_val[i] = card(B_str[i]);
        if (A_val[i] == -1 || B_val[i] == -1){
            printf("Input Error!\n");
            return 0;
        }
    }
    if (check(A_val) || check(B_val)){
        printf("Input Error!\n");
        return 0;
    }
    sort(A_str, A_val);
    sort(B_str,B_val);
    for (int i = 0; i < 3; i++){
        if (A_val[i] > B_val[i]){
            printf("Winner is A!\n");
            break;
        }else if (A_val[i] < B_val[i]){
            printf("Winner is B!\n");
            break;
        }else{if (i == 2) printf("Winner is X!\n");
            else continue;
        }
    }
    printf("A: %s %s %s\n",A_str[0],A_str[1],A_str[2]);
    printf("B: %s %s %s\n",B_str[0],B_str[1],B_str[2]);
    return 0;
}
