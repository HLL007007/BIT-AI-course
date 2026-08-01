# include <stdio.h>
# include <string.h>
char big(char c, int n){
	return ((c - 'A' + n) % 26 + 26) % 26 + 'A';
}
char small(char c, int n){
	return ((c - 'a' + n) % 26 + 26) % 26 + 'a';
}
int main(){
	char s1[20];
	int key[20];
	gets(s1);
	int key_len = strlen(s1); 
	int i;
	for (i = 0; i < key_len; i++){
		key[i] = s1[i] - 'A';
	}
	int current = 0;
	char s[205];
	gets(s);
	int len = strlen(s);
	for (i = 0; i < len; i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
		   if (current >= key_len){
				current = 0;
			}
			s[i] = small(s[i],key[current]);
			current++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z'){
			if (current >= key_len){
				current = 0;
			}
			s[i] = big(s[i],key[current]);
			current++;
		}
	}
	printf("%s\n",s);
	return 0;
}
