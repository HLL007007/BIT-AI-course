# include <stdio.h>

void move(int n, char from, char to, char use){
    if (n == 1) {printf("%c -> %c\n",from,to); return ;}
    else {
        move(n-1,from,use,to);
        printf("%c -> %c\n",from,to);
        move(n-1,use,to,to);
    }
}

int main(){
    int n;
    if (scanf("%d",&n) != 1) return 0;
    move(n,'A','C','B');
    return 0;
}