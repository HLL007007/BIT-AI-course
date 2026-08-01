# include <stdio.h>

int main(){
	int w;
	scanf("%d",&w);
	int mid = (w - 1) / 2 + 1;
	int i , j;
	for (i = 1; i <= mid; i++){
		for (j = 1; j <= mid + i - 1; j++){
			if(j == i + mid - 1 || j == mid - i + 1){
				printf("A");
			}
			else printf(" ");
		}
		printf("\n");
	}
	for (j = 1; j <= w; j++){
		printf("A");
	}
	printf("\n");
	for (i = mid + 2; i <= w; i++){
		for (j = 1; j <= w ;j++){
			if (j == 1 || j == w){
				printf("A");
			}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
