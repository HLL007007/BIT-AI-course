# include <stdio.h>
# include <stdlib.h>
int n, z;
int x[105];       // 保存各灯的位置
int w[105];       // 保存各灯的功率
int min_cost = 0x7fffffff; // 记录最小总消耗，初始化为一个极大值


void findw(int pos, int left ,int right ,int time ,int cost){
	if(cost >= min_cost) return ;
	if (left < 1 && right > n) {
		if (cost < min_cost){
			min_cost = cost; 
		}
		return ;
	}
	if (left >= 1){
		int dist = abs(pos - x[left]);
		int next_time = time + dist;
		int next_cost = cost + w[left] * next_time;
		findw(x[left],left - 1,right,next_time,next_cost);
	}
	if (right <= n){
		int dist = abs(x[right] - pos);
		int next_time = time + dist;
		int next_cost = cost +  w[right] * next_time;
		findw(x[right],left,right + 1,next_time,next_cost);
	}
}
int main(){
	scanf("%d %d",&n,&z);
	int i , j;
	for (i = 1; i <= n; i++){
		scanf("%d %d",&x[i],&w[i]);
	}
	int left = 0;
	int right = n + 1;
	for (i = 1; i <=n ;i++){
		if(x[i] < z){
			left = i;
		}
	}
	for (i = n; i >= 0; i--){
		if (x[i] > z){
			right = i;
		}
	}
	findw(z,left,right,0,0);
	printf("%d",min_cost);
	return 0;
	
}
