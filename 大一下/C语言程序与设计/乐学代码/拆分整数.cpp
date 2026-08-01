# include <stdio.h>

int count(int n,int m );
int main()   
{  
   int a;  
   scanf("%d", &a);  
   printf("%d\n", count(a, a-1));    
   return 0;  
}

int count(int n,int m ){
    if (n < 1 || m < 1) return 0;
    else if (n == 1 || m == 1) return 1;
    else if (n < m) return count(n,n);
    else if (n == m) return count(n,m - 1) + 1;
    else return count(n,m - 1) + count(n - m, m); 
}   