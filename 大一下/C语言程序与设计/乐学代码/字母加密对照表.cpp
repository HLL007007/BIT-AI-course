# include <stdio.h>

int main(){
    char map[128];
    for (int i = 0; i < 128; i++){
        map[i] = (char)i;
    }
    char str1[] = "abcdeik;w";
    char str2[] = "dwk;iabce";
    for (int i = 0; i < 9; i++){
        map[(int)(str1[i])] = str2[i];
    }
    char c;
    while((c = getchar()) != EOF && c != '\n'){
        putchar(map[(int)c]);
    }
    printf("\n");
    return 0;
}