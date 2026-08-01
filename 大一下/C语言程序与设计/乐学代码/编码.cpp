#include <stdio.h>
#include <string.h>

int C[30][30] = {0};

void init_combinations() {
    for (int i = 0; i <= 26; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int get_C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return C[n][m];
}

int main() {
    init_combinations(); 
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    while (N--) {
        char str[15];
        scanf("%s", str);
        
        int len = strlen(str);
        int is_valid = 1;
        
        for (int i = 0; i < len; i++) {
            if (str[i] < 'a' || str[i] > 'z') {
                is_valid = 0;
                break;
            }
            if (i > 0 && str[i] <= str[i-1]) {
                is_valid = 0;
                break;
            }
        }
        
        if (!is_valid) {
            printf("0\n");
            continue;
        }
        
        int ans = 0;

        for (int i = 1; i < len; i++) {
            ans += get_C(26, i);
        }
        
        for (int i = 0; i < len; i++) {
            char start_char = (i == 0) ? 'a' : (str[i-1] + 1);
            
            for (char c = start_char; c < str[i]; c++) {
                int x = c - 'a' + 1; 
                ans += get_C(26 - x, len - 1 - i);
            }
        }
        ans += 1;
        
        printf("%d\n", ans);
    }
    
    return 0;
}