# include <stdio.h>
# include <ctype.h>
char op1(char ch){
	char res;
	if (ch >= 'a' && ch <= 'z'){
		res = 'A' + ch - 'a';
	}
	else{
		res = 'a' + ch - 'A';
	}
	return res;
} 

char op2(char n){
	char ans = '9' - (n - '0');
	return ans;
}

int main(){
	char c;
	char numbers[10000];
	int i = 0;
	char alpha[10000];
	int j = 0;
	while((c = getchar()) != EOF){
		if (c == '\n') break;
		if(isalpha(c)){
			alpha[i] = op1(c);
			i++;
		}
		else if (c >= '0' && c <= '9'){
			numbers[j] = op2(c);
			j++;
		}
	}
	int t , k;
	for(t = 0; t < j; t++){
		printf("%c",numbers[t]);
	}
	for(k = 0; k < i; k++){
		printf("%c",alpha[k]);
	}
	printf("\n");
	return 0;
}
