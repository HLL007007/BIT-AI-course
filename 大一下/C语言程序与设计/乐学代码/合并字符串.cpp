# include <stdio.h>
# include <string.h>
# include <ctype.h>
# define N 100000

int main(){
    char a[N] , b[N] , res[2*N];
    gets(a);
    gets(b);
    int len_a = strlen(a);
    int len_b = strlen(b);

    int i = 0 , j = 0 , k = 0;
    while (i < len_a && j < len_b){
        if (a[i] < b[j]){
            res[k++] = a[i++];
        }
        else{
            res[k++] = b[j++];
        }
    }
    while(i < len_a){
        res[k++] = a[i++];
    }
    while(j < len_b){
        res[k++] = b[j++];
    }
    res[k] = '\0';
    printf("%s",res);
    return 0;

}
