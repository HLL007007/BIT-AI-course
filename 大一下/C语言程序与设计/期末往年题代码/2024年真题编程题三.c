#include <stdio.h>  
int isElement(int,int);
int main()  
{  int k,x,s,isElement(int ,int);  
   scanf("%d %d", &k,&x);  
   s = isElement(k,x);  
   if(s){  
        printf("YES\n");  
   }  
   else{  
       printf("NO\n");  
   }  
   return 0;  
}
int isElement(int k,int x){
	if (k > x) return 0;
	if (k == x || 2 * k + 1 == x || 3 * k + 1 == x){
		return 1;
	}
	else return isElement(2*k+1,x) || isElement(3*k+1,x);
}