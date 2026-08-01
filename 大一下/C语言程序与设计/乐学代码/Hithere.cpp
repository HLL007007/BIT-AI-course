# include <stdio.h>
# include <string.h>
# define N 1000

int main(){
    char name[N];
    gets(name);
    printf("Hi,there,");
    int n = strlen(name);
    name[n] = '!';
    name[n + 1] = '\0';
    puts(name);
    return 0;
}