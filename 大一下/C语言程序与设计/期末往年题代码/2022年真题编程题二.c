# include <stdio.h>
long long path_cnt(int x1,int y1,int x2,int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	long long a[dy + 1][dx + 1];
	long long i , j;
	for (i = 0; i <= dy; i++){
		for (j = 0; j <= dx; j++){
			a[i][j] = 0;
		}
	}
	for (j = 0; j <= dx; j ++){
		a[0][j] = 1;
	}
	for (i = 0; i <= dy; i ++){
		a[i][0] = 1;
	}
	for (i = 1; i <= dy; i++){
		for (j = 1; j <= dx; j++){
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	return a[dy][dx]; 
}
void min_path(int p ,int q, int n, int m){
	int x = 0;
	int y = 0;
	while (x < p){
		printf("(%d,%d)",x,y);
		x++;
	}
	while (y < q){
		printf("(%d,%d)",x,y);
		y++;
	}
	while (x < n){
		printf("(%d,%d)",x,y);
		x++;
	}
	while (y <= m){
		printf("(%d,%d)",x,y);
		y++;
	}
	printf("\n");
}
int main(){
	int p , q , n , m;
	// (p , q) 为中间点 ， (n , m) 为终点 
	scanf("%d %d",&n,&m);
	scanf("%d %d",&p,&q); 
	long long res1 = path_cnt(0,0,p,q);
	long long res2 = path_cnt(p,q,n,m);
	long long ans = res1 * res2;
	printf("%lld\n",ans);
	min_path(p,q,n,m);
	return 0;
}
