# include <stdio.h>

int main(){
	int n , m; // n 行 m 列 
	scanf("%d %d",&m,&n);
	int a[n][m];
	int p , q;
	for (p = 0; p < n; p++){
		for (q = 0; q < m; q++){
			a[p][q] = -1;
		}
	}
	int count = 0; // count = n * m 停止
	int cur = 0; // 目前的数字，取余代表填充方向
	int i = 0;
	int j = 0;
	while(count < n * m){
		if (cur % 4 == 0){ // 横
		    while(j < m && a[i][j] == -1 ){
               a[i][j] = cur;
			   count++;
			   j++;
            }
            j -= 1;
            i += 1;
		}
		else if(cur % 4 == 1){ // 竖 
            while(i < n && a[i][j] == -1){
               a[i][j] = cur;
			   count++;
			   i++;
            }
            i -= 1;
            j -= 1;
		}
		else if(cur % 4 == 2){
			while(j >= 0 &&  a[i][j] == -1){
               a[i][j] = cur;
			   count++;
			   j--;
            }
            j += 1;
            i -= 1;
		}
		else{
			while(i >= 0 && a[i][j] == -1){
               a[i][j] = cur;
			   count++;
			   i--;
            }
            i += 1;
            j += 1;
		}
		cur++;
	}
	for (p = 0; p < n; p++){
		for (q = 0; q < m; q++){
			printf("%d",a[p][q]);
		}
		printf("\n");
	}  
	return 0;
} 





