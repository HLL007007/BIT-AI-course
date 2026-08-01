# include <stdio.h>
void ou(int n);
void tu(int n);

int main(){
	int n;
	scanf("%d",&n);
	if (n % 2 == 0){
		ou(n);
	}
	else{
		tu(n);
	}
	return 0; 
}

void ou(int n){
	int w = n + (n - 1) / 2;
	int i , j;
	for (j = 1; j <= w; j++){
		if ((j >= 1 && j <= n / 2) || (j <= w && j >= (w - n / 2 + 1))) printf("*");
		else printf(" ");
	}
	printf("\n");
	for (i = 1; i <= n / 3; i++){
		for (j = 1; j <= w; j++){
			if(j == 1 || j == n / 2 || j == (w - n / 2 + 1) || j == w) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for(j = 1; j <= w; j++){
		if (j == 1 || (j >= n / 2 && j <= (w - n / 2 + 1) )|| j == w) printf("*");
		else printf(" ");
	}
	printf("\n");
	for (i = 1; i <= n / 2 - 1; i++){
		for (j = 1; j <= w; j++){
			if (j == 1 || j == w) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (j = 1; j <= w; j++){
		printf("*");
	}
	printf("\n");
	return ;
}

void tu(int n){
	int w = n / 2 * 3;
	int i , j;
	for (j = 1; j <= n; j++){
		if (j >= n / 2 && j <= n) printf("*");
		else printf(" ");
	}
	printf("\n");
	for (i = 1; i <= n / 3; i++){
		for (j = 1; j <= n; j++){
			if (j == n / 2 || j == n) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (j = 1; j <= w; j++){
		if ((j >= 1 && j <= n / 2) || (j >= n && j <= w)) printf("*");
		else printf(" ");
	}
	printf("\n");
	for (i = 1; i <= n / 2 - 1; i++){
		for (j = 1; j <= w; j++){
			if (j == 1 || j == w) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (j = 1; j <= w; j++){
		printf("*");
	}
	printf("\n");
	return ;
}



