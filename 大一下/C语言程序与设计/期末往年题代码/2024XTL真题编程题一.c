# include <stdio.h>

char next(char c){
	char ans = ((c - 'A' + 1) % 26 + 26) % 26 + 'A';
	return ans;
} 

int main(){
	int n;
	char current;
	scanf("%d %c",&n,&current);
	char a[n][n];
	int i , j;
	for (i = 0; i < n;i++){
		for (j = 0; j < n; j++){
			a[i][j] = ' ';
		}
	}
	i = 0;
	j = 0;
	while(a[i][j] == ' '){
		if(i % 2 == 0){
			// zuo
			for (j = 0; j < n; j++){
				a[i][j] = current;
				current = next(current);
			}
			i++;
			j--;
		}
		else{
			for (j = n - 1; j >= 0; j--){
				a[i][j] = current;
				current = next(current);
			}
			i++;
			j++;
		} 
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
