# include<stdio.h>
# include<stdlib.h>
int gcd(int a, int b);

void result(int a1, int b1, char c, int a2, int b2 , int a, int b);

int main(){
	int a1 , a2 , b1 , b2;
	int a = 0 ; int b = 1;
	char c;
	
	scanf("%d/%d %c %d/%d",&a1,&b1,&c,&a2,&b2);
	
	if (c == '+'){
		a = a1 * b2 + a2 * b1;
        b = b1 * b2;
	}
	else if(c == '-'){
        a = a1 * b2 - a2 * b1;
        b = b1 * b2;		
	}
	else if(c == '*'){
        a = a1 * a2;
        b = b1 * b2;		
	}
	else{
		a = a1 * b2;
        b = b1 * a2;
	}
	
	result(a1 , b1 , c , a2 , b2 , a , b);
	
	return 0;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void result(int a1, int b1, char c, int a2, int b2 , int a, int b){
	if (b < 0) {
	   a = -a;
	   b = -b;
    }
	
	if (a == 0) {
		printf("%d/%d %c %d/%d = 0\n",a1,b1,c,a2,b2);
        return;
	}
	
	int d = gcd(a , b);
	a /= d;
	b /= d;
	
	if (b == 1) printf("%d/%d %c %d/%d = %d\n",a1,b1,c,a2,b2,a);
	else printf("%d/%d %c %d/%d = %d/%d\n",a1,b1,c,a2,b2,a,b);
}