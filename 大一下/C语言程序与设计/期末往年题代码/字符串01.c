# include <stdio.h>
# include <string.h>
int main(){
	char words[100][100];
	int times[100];
	char temp[100];
	int cnt = 0; // 不重复总数 
	int i , j;
	while(scanf("%s",temp) != EOF){
		if (strcmp(temp,"0") == 0) break;
		int flag = 0;
		for (i = 0; i < cnt; i++){
			if (strcmp(words[i],temp) == 0){
				flag = 1;
				times[i]++;
				break;
			}
		}
		if(!flag){
			strcpy(words[cnt], temp);
			times[cnt] = 1;
			cnt++;
		}
	}
	char cf[100][100];
	int count = 0;
	for (i = 0; i < cnt; i++){
		if (times[i] > 1){
			strcpy(cf[count], words[i]);
			count++;
		}
	}
	if (count == 0) {
		printf("none\n");
		return 0;
	}
	if (count == 1) {
		printf("%s\n",cf[0]);
		return 0;
	}
	for (i = 0; i < count - 1; i++){
		for (j = 0; j < count - 1 - i; j++){
			if (strcmp(cf[j],cf[j + 1]) > 0){
				char temp_w[100];
				strcpy(temp_w,cf[j]);
				strcpy(cf[j], cf[j + 1]);
				strcpy(cf[j + 1], temp_w);
			}
		}
	}
	for (i = 0; i < count; i++){
		printf("%s\n",cf[i]);
	}
	return 0;
}
