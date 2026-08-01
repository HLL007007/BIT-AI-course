#include <stdio.h>  
  
// 递归函数-----------需要补全   
int func(int n);  
  
int main()       
{      
   int n, result;      
   scanf("%d", &n);  
   result = func(n);  
   printf("f(%d)=%d\n", n, result);  
   return 0;      
}  
  
int func(int n){
    if (n >= 20){
        printf("f(%d)=%d\n",n,n-4);
        return n - 4;
    }
    else if(n >= 10 && n < 20){
        printf("f(%d)=f(f(%d)+5)\n", n, n + 8);
        int res1 = func(n + 8);
        int res2 = func(res1 + 5);
        return res2;
    }
    else{
        printf("f(%d)=f(f(%d))\n",n,n+7);
        int res1 = func(n+7);
        int res2 = func(res1);
        return res2;
    }
}