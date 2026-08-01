#include <stdio.h>

int main() {
    char ch;
    int height;

    if (scanf(" %c%d", &ch, &height) != 2) {
        return 1; 
    }

    for (int i = 1; i <= height; i++) {
        for (int s = 0; s < height - i; s++) {
            printf(" ");
        }

        int num_chars = 2 * i - 1;
        
        for (int j = 1; j <= num_chars; j++) {
            if (i == height || j == 1 || j == num_chars) {
                printf("%c", ch);
            } else {
                printf(" "); 
            }

            if (ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A' + 1) % 26 + 'A';
            } else if (ch >= 'a' && ch <= 'z') {
                ch = (ch - 'a' + 1) % 26 + 'a';
            } else {
                ch++; 
            }
        }

        printf("\n");
    }

    return 0;
}