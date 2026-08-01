# include<stdio.h>
# include<math.h>
int main(){
	int h , m;
	double a1 , a2 , diff , angle;
	scanf("%d %d",&h,&m);
	a1 = m * 6.0;
	a2 = (h % 12) * 30.0 + m * 0.5;
	diff = fabs(a1 - a2);
	angle = fmin(diff , 360.0 - diff);
	printf("At %d:%02d the angle is %.1f degrees.\n",h,m,angle);
	return 0;
}