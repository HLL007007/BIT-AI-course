# include <stdio.h>

int main(){
	int n , m;
	scanf("%d %d",&n,&m);
	char a[n][m];
	int i , j , k;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf(" %c",&a[i][j]);
		}
	}
	int ans[105][2];
	int cnt = 0;
	for (i = 1; i < n - 2; i++){
		for (j = 1; j < m - 2; j++){
			if (a[i][j] == 'A' && a[i+1][j] == 'A' && a[i][j+1] == 'A' && a[i+1][j+1] == 'A'){
				if (a[i-1][j-1] == 'E' && a[i-1][j] == 'E' && a[i-1][j+1] == 'E' && a[i-1][j+2] == 'E' && a[i][j-1] == 'E'&&  a[i][j+2] == 'E'&& a[i+1][j-1] == 'E' && a[i+1][j+2] == 'E' && a[i+2][j-1] == 'E' && a[i+2][j] == 'E' && a[i+2][j+1] == 'E' && a[i+2][j+2] == 'E'){
					ans[cnt][0] = i;
					ans[cnt][1] = j;
					cnt++;
					a[i][j] = 'X';
					a[i+1][j] = 'X';
					a[i][j+1] = 'X';
					a[i+1][j+1] = 'X';
				}
			}
		}
	}
	for (k = 0; k < cnt; k++){
		printf("%d %d\n",ans[k][0],ans[k][1]);
	}
	return 0;
} 
