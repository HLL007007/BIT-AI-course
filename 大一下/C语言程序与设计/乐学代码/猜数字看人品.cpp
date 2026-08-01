# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(){
    int num;
    while ((scanf("%d",&num) != 0) && num >= 1 && num <= 10){
        int low = 1;
        int high = 10;
        char ans1[20];
        char ans2[20];
        int last_num = num;
        while (scanf("%s %s",ans1, ans2) == 2 && (strcmp(ans1,"right") != 0 && strcmp(ans2,"on") != 0)){
            if (strcmp(ans1,"too") == 0 && strcmp(ans2,"low") == 0){
                if (last_num + 1 > low){
                    low = last_num + 1;
                }
            }
            else if (strcmp(ans1,"too") == 0 && strcmp(ans2,"high") == 0){
                if (last_num - 1 < high){
                    high = last_num - 1;
                }
            }
            else {
                return 0;
            }
            if (scanf("%d",&last_num) != 1 || last_num < 1 || last_num > 10){
                return 0;
            }
        }
        if (low <= last_num && last_num <= high){
            printf("Tom may be honest\n");
        }
        else {
            printf("Tom is dishonest\n");
        }
        continue;
    }
    return 0;
}