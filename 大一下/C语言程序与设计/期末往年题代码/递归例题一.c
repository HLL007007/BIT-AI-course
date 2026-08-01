# include <stdio.h>
int a[1000];
void puta(int n){
	int t;
	for (t = 1; t <= n - 1; t++){
		printf("%d+",a[t]);
	}
	printf("%d\n",a[n]);
	return ;
}
void f(int n,int m,int i){
	if (n == 0){
		puta(i - 1);
		return;
	}
	if(n < m) m = n;

	// xuan m
	a[i] = m;
	f(n - m,m,i + 1);
	
	// buxuan m
	if (m > 1){
		f(n,m-1,i);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	f(n,n,1);
	return 0;
} 
