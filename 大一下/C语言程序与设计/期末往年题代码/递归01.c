# include <stdio.h>
char path[25];
void cmb(int n,int unmatched,int step){
	if (step == 2 * n){
		path[step] = '\0';
		printf("%s\n",path);
		return;
	}
	int left_used = (step + unmatched) / 2;
	
	if (left_used < n){
		path[step] = '(';
		cmb(n,unmatched + 1,step + 1);
	}
	if (unmatched){
		path[step] = ')';
		cmb(n, unmatched - 1, step + 1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	cmb(n,0,0);
	return 0;
} 
