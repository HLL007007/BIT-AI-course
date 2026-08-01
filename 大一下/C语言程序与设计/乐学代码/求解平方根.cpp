#include <stdio.h>  
#include <math.h>  
  
double my_sqrt(double, double, double);  
  
int main(int argc, char **argv)  
{  
   double x, e;  
   scanf("%lf,%lf", &x, &e);  
   printf("%.8lf\n", my_sqrt(x, x/2, e));  
   return 0;  
}  

double my_sqrt(double x, double p, double e){
    if (fabs(p*p - x) < e) return p;
    return my_sqrt(x,(p + x/p)/2,e);
}