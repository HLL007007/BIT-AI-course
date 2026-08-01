//数组练习 02：甲乙两个人有 n(小于 100)匹马进行赛马，每匹马有不同的速度 v，共进行 
//n 场一对一比赛，甲如何制定策略才能取得最好成绩，输出最好成绩。 
//（赢一场记 1 分，输一场记-1 分，平局记 0 分，累计得分为最后成绩） 
//贪心策略：1）尽可能赢得每场比赛 2）如果不能赢，则让当前最慢的马贡献值最大，即 
//消耗对手最快的马，贪心策略编程要点：先排序再处理 

# include<stdio.h>
#define N 100
void sort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n , a[N] , b[N] , h , t;
    int score = 0;
    if (scanf("%d",&n) != 1) return 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&b[i]);
    }
    sort(a, n);
    sort(b, n);
    // 开始比赛
    h = 0;
    t = n - 1;
    for (int i = 0; i < n; i++){
        if (a[i] > b[h]){
            score++;
            h++;
        }
        else if(a[i] < b[h]){
            score--;
            t--;
        }
        else{
            if (a[i] < b[t]){
                score--;
                t--;
            }
            else{
                score += 0;
                t--;
            }
        }
    }
    printf("%d\n", score);
    return 0;
}