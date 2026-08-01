# include<stdio.h>
int is_leapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	} 
	else return 0;
}
int main(){
	int year;
	int total = 0;
	scanf("%d",&year);
    // 1900.1.1 -- 1
    for(int i = 1900 ; i < year ; i++){
  		if (is_leapYear(i)) total += 366;
		else total += 365;
    }
    if (is_leapYear(year)) total += 31 + 29 + 31 + 30;
    else total += 31 + 28 + 31 + 30;
    int week = (total + 1) % 7;  //5月1号是星期几
    if (week == 0) week = 7;
    printf("%d\n",14 - week + 1);
}