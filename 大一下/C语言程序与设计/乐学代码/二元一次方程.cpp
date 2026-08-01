# include<stdio.h>
# include<math.h>
int main(){
	double a , b , c , delta , x1 , x2;
	double t1 , t2;
	scanf("%lf %lf %lf",&a,&b,&c);
	if (a == 0){
		if (b == 0) printf("Input error!\n");
        else {
        	if (c == 0) printf("x=0.000000\n");
        	else printf("x=%.6f\n",(-1) * c / b); 
		}
	}
	else{
		delta = b * b - 4 * a * c;
        if (delta == 0) {
        	if (b == 0 && c == 0) printf("x1=x2=0.000000\n");
        	else printf("x1=x2=%.6f\n",(-1) * b / (2 * a));
		}
        else if(delta >= 0){
        	x1 = (- b + sqrt(delta)) / (2 * a);
        	x2 = (- b - sqrt(delta)) / (2 * a);
        	printf("x1=%.6f\n",x1);
        	printf("x2=%.6f\n",x2);
		}
	    else{
    	    t1 = - b / (2 * a);
            t2 = sqrt(-delta) / (2 * a);
            if (t1 == 0){
                printf("x1=%.6fi\n",t2);
                printf("x2=-%.6fi\n",t2);	
			}
            else{
       	        printf("x1=%.6f+%.6fi\n",t1,t2);
 	            printf("x2=%.6f-%.6fi\n",t1,t2);
			}
		}
	}
	return 0;
}