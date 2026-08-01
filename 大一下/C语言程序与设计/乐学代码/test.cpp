#include<stdio.h>
int main(){
    int a[10] = {0};
    char ch;
    while((ch = getchar()) != EOF && ch != '\n'){
        switch (ch){
            case 'M': a[0]++;break;
            case 'A': a[1]++;break;
            case 'T': a[2]++;break;
            case 'I': a[3]++;break;
            case 'J': a[4]++;break;            
            case 'm': a[5]++;break;
            case 'a': a[6]++;break;
            case 't': a[7]++;break;
            case 'i': a[8]++;break;
            case 'j': a[9]++;break;
        }
    }
    int ans1 , ans2;
    ans1 = a[0];
    ans2 = a[5];
    for (int i = 1; i <= 4; i++){
        if (i == 3){
            if (ans1 > (a[i] / 2)) ans1 = a[i] / 2;
        }
        else{
            if (ans1 > a[i]) ans1 = a[i];
        }
    }
    for (int i = 6; i <= 9; i++){
        if (i == 8){
            if (ans2 > (a[i] / 2)) ans2 = a[i] / 2;
        }
        else{
            if (ans2 > a[i]) ans2 = a[i];
        }
    }
    printf("%d %d",ans1,ans2);


    return 0; 
}