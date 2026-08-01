# include <stdio.h>

char next(char c){
	char ans = ((c - 'A' + 1) % 26 + 26) % 26 + 'A';
	return ans;
}
int main(){
	int w;
	char current = 'A';
	
	scanf("%d",&w);
	
	int i , j;
	for (i = 1; i <= w; i++){
		for (j = 1; j <= 2 * w  - i; j++){
			if (j >= i){
			   printf("%c",current);
			   current = next(current);
			}
			else printf(" ");
		}
		printf("\n");
	}
	
}
