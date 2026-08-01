#include <stdio.h>

int findf(int n);  
  
int main()  
{  int n,s;  
   scanf("%d", &n);  
   s = findf(n);  
   printf("%d\n", s);  
   return 0;  
}

int findf(int n){
    if (n <= 0) return 1;
    if (n % 2 == 0) return n * findf(n - 1);
    else return n + 1 -  findf(n - 2);
}