#include <stdio.h>  
void PrintChar(int number,char c){  
    int i;  
    for ( i=0 ; i< number; i++)  
        printf("%c",c);  
}  
  
// 递归函数-----------需要补全  
char RecursionFunction(int n, char c){
	if(n <= 0){
		printf("\nRecursionFunction has been over !\n");
		return ;
	}
	else{
		if(c == '#') {
			PrintChar(n,c); 
			return RecursionFunction(n-1, '*');
		}
		else if(c == '*') {
			PrintChar(n,c);
			return RecursionFunction(n+2, '?');
		}
		else if(c == '?') {
			PrintChar(n,c);
			return RecursionFunction(n+3, '+');
		}
		else if(c == '+') {
			PrintChar(n,c);
			return RecursionFunction(n-6, '#');
		}
	}
}  
  
int main(){  
    char c; int n;  
    scanf("%d %c",&n,&c);  
    RecursionFunction(n,c);  
    return 0;  
}  
