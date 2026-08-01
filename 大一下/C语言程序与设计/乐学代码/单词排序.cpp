# include <stdio.h>
# include <string.h>

int main(){
    char a[5][10000];
    for (int i = 0; i < 5; i++){
        if (gets(a[i]) == NULL) return 0;
    }
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4 - i; j++){
            if (strcmp(a[j] , a[j + 1]) < 0){
                char temp[1000];
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    for (int i = 0; i < 5; i++){
        puts(a[i]);
    }
    return 0;
}