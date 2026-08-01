# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 1 || n > 50) return 0;
    int a[n];
    for (int i = 0; i < n; i++){
        if (scanf("%d", &a[i]) != 1) return 0;
    }
    int flag = 0;
    int left_index , right_index;
    for (int left = 0; left < n - 1; left++){
        int right = left + 1;
        while (right < n && a[right] == a[left]){
            right++;
        }
        if ((right - left > 1) && flag == 0){
            flag = 1;
            left_index = left;
            right_index = right - 1;
        }
        if ((right - left - 1) > (right_index - left_index)){
            left_index = left;
            right_index = right - 1;
        }
    }
    if (flag) printf("The longest equal number list is from %d to %d.\n",left_index,right_index);
    else printf("No equal number list.\n");
    return 0;
}