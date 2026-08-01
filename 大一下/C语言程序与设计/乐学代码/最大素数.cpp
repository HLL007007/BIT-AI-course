# include<stdio.h>
# include<math.h>
int main(){
	int n;
	if (scanf("%d",&n) != 1){
		return 0;
	}
	if (n < 2){
		return 0;
	}
    int ans = 0;
	for (int i = 2;i <= n;i++){
		int num = i;
		if (num == 2){
		   	ans = 2;
		}
	    else{
    	    int cnt = 0;
			for (int j = 2;j <= sqrt(num);j++){
				if (num % j == 0) cnt = 1;
		    }
		    if (cnt == 0){
        	    ans = num;
		    }
	    }
    }
	printf("The max prime number is %d.\n",ans);
	return 0;
}