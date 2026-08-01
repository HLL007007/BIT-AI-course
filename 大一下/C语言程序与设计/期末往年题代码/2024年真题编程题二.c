# include <stdio.h>
# include <string.h>
# include <ctype.h>
typedef struct{
	char word[25];
	int count;
}WordFerq;

WordFerq words[10000];
int word_num = 0;

void add_word(char *w){
	int k;
	for (k = 0; k < word_num; k++){
		if(strcmp(words[k].word,w) == 0){
			words[k].count++;
			return;
		}
	}
	strcpy(words[word_num].word,w);
	words[word_num].count = 1;
	word_num++;
}
int main(){
	char line[100];
	int i , j;
	while(fgets(line,sizeof(line),stdin)){
		if (line[0] == '\n') break;
		
		char temp_word[25];
		int temp_len = 0;
		
		for (i = 0; line[i] != '\n'; i++){
			if(isalpha(line[i])){
				temp_word[temp_len] = tolower(line[i]);
				temp_len++;
			}
			else if (temp_len > 0){
				temp_word[temp_len] = '\0';
				add_word(temp_word);
				temp_len = 0;
			}
		}
		if (temp_len>0){
			temp_word[temp_len] = '\0';
			add_word(temp_word);
		}
	}
	
	for (i = 0; i < word_num - 1; i++){
		for (j = 0; j < word_num - 1 - i; j++){
			int flag = 0;
			if (words[j].count < words[j + 1].count){
				flag = 1; // 标记是否要交换顺序 
			}
			else if (words[j].count == words[j + 1].count){
				if (strcmp(words[j].word,words[j+1].word) > 0){
					flag = 1;
				}
			}
			if (flag){
				WordFerq temp;
				temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp; 
			} 
		}
	}
	for (j = 0; j < word_num; j++){
		printf("%s %d\n",words[j].word,words[j].count);
	}
	return 0;
} 
