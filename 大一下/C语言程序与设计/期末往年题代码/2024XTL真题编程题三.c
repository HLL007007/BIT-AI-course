# include <stdio.h>

long long f(long long n){
	if (n <=4 && n >= 1){
		return 1;
	}
	else if(n > 4 && n % 2 == 0){
		return f(n - 2) + f(n - 4);
	}
	else if(n > 4 && n % 2 == 1){
		return f(n - 1) + f(n - 3);
	}
}
int main(){
	long long n;
	scanf("%lld",&n);
	printf("f(%lld) = %lld\n",n,f(n));
	return 0;
} 
