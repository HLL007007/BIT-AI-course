 #include <stdio.h>  
void cmb(int step, int l);  //step 为步骤计数，l为还未匹配的左括号数量  
char a[20];  //存放输出串  
int n; 
int main() {  
    scanf("%d", &n);  
    cmb(1, 0);        //在cmb中输出  
    return 0;  
}
void cmb(int step,int l){
    if (step > 2 * n){
        for (int i = 0; i < 2 * n; i++){
            printf("%c",a[i]);
        }
        printf("\n");
        return;
    }
    if (step + l <= 2 * n){
        a[step - 1] = '(';
        cmb(step + 1, l + 1);
    }
    if (l){
        a[step - 1] = ')';
        cmb(step + 1, l - 1);
    }
}  