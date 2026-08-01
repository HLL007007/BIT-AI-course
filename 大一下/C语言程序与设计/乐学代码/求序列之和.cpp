# include <stdio.h>

double calculate(int a){
    if (a == 1) return 1.0;
    else{
        double t = 1.0 / a;
        if (a >= 3 && a % 2 == 1) t = -t;
        return t + calculate(a - 1);
    }
}
int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    double ans = calculate(n);
    printf("%.6lf\n", ans);
    return 0;
}