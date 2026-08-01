# include <stdio.h>
# include <math.h>
double area(double a[],double b[],double c[]){
    double s = 0.5*(fabs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1] - a[1]*b[0] - b[1]*c[0] - c[1]*a[0]));
    return s;
}

int main(){
    int times;
    if (scanf("%d",&times)!= 1) return 0;
    double max_areas[times];
    for(int j = 0; j < times; j++){
        int n;
        if (scanf("%d",&n)!= 1) return 0;
        if (n < 3) continue;
        double nums[n][2];
        for (int i = 0; i < n; i++){
            scanf("%lf %lf",&nums[i][0],&nums[i][1]);
        }
        double max_area = 0.0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                for (int k = j+1; k < n; k++){
                    double s = area(nums[i],nums[j],nums[k]);
                    if (s > max_area) max_area = s;
                }
            }
        }
        max_areas[j] = max_area;
    }
    for (int i = 0; i < times; i++){
        printf("%.1f\n",max_areas[i]);
    }
}