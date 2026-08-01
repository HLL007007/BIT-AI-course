# include<stdio.h>
int main(){
	int n;
	char c;
	if (scanf("%d %c",&n,&c) == 0 ) return 0;
	if (n < 1 || n > 50) return 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (i == j || i + j == n + 1) printf("%c",c);       	 	
	 	    else printf(" ");
		}
	    printf("\n");
	}
	return 0;
}