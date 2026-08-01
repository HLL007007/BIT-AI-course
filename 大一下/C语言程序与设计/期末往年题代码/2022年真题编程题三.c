# include <stdio.h>
int f(int n,int k){
	if (n == 1) return 0;
	if (n == 2){
		if (k == 1) return 0;
		if (k == 2) return 1;
	}
	int num = 1;
	int pow;
	for (pow = 1; pow < n; pow ++){
		num *= 2;
	}
	int mid = num / 2;
	if (k <= mid) return f(n - 1,k);
	else return 1 - f(n - 1, k - mid);
}
int main(){
	int n , k;
	scanf("%d %d",&n,&k);
	int ans = f(n,k);
	printf("%d\n",ans);
	return 0;
}
