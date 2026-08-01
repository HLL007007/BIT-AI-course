# include<stdio.h>
int main(){
	char c;
	scanf("%c",&c);
	if (c <= 'z' && c >= 'a') printf("%c\n",c - 32);
	else if (c <= 'Z' && c >= 'A') printf("%c\n",c + 32);
	else printf("%c\n",c);
	return 0;   
}