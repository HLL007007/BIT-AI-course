
#include <stdio.h>  
#include <stdlib.h>  
#define N 100  
int sum=0,n ,z, x[N], w[N];  
void findw(int pos, int l, int r, int time, int wt);  
int main()  
{  
    int l=0,r;  
    scanf("%d%d", &n, &z);  
    for(int i=1; i<=n; i++){  
        scanf("%d%d", &x[i], &w[i]);  
        if(z>=x[i]) l = i;  
    }  
    r = l + 1;  
    findw(z, l, r, 0, 0);  //0,0为当前总时间消耗和能源消耗  
    printf("%d\n", sum);  
}
#include <math.h>
void findw(int pos, int l, int r, int time, int wt){
    if (sum != 0 && wt >= sum){
        return;
    }
    if (l < 1 && r > n){
        if (sum == 0 || sum > wt){
            sum = wt;
        }
        return;
    }
    if (l >= 1){
        int dist = abs(pos - x[l]);
        int next_time = time + dist;
        int next_wt = wt + w[l] * next_time;
        findw(x[l] , l - 1 , r , next_time , next_wt);
    }
    if (r <= n){
        int dist = abs(x[r] - pos);
        int next_time = time + dist;
        int next_wt = wt + w[r] * next_time;
        findw(x[r] , l , r + 1 , next_time , next_wt);
    }
}