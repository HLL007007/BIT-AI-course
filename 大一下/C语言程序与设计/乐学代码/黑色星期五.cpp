# include <stdio.h>
int is_leapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	} 
	else return 0;
}
int check(int year,int month,int day){
	int total = 0;
    // 1900.1.1 -- 1
    for(int i = 1900 ; i < year ; i++){
  		if (is_leapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1 ; i < month ; i++){
		if (i == 2){
		   	if(is_leapYear(year)){
				  total += 29;
  			}
	 	    else total += 28;
		}
		else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) total += 31;
		else total += 30;
	}
	total += day;
	int ans = total % 7;
    return ans;
}
int main(){
    int year;
    if (scanf("%d",&year) != 1) return 0;
    int p = 0;
    int b[12][3];
    for (int month = 1; month <= 12; month++){
        int ans = check(year,month,13);
        if (ans == 5){
            b[p][0] = year;
            b[p][1] = month;
            b[p][2] = 13;
            p++;
        }
    }
    if (p == 0) return 0;
    else if (p == 1){
        printf("There is 1 Black Friday in year %d.\n",year);
        printf("It is:\n");
        printf("%d/%d/%d\n",b[0][0],b[0][1],b[0][2]);
        return 0;
    }
    else{
        printf("There are %d Black Fridays in year %d.\n",p,year);
        printf("They are:\n");
        for (int i = 0; i < p; i++){
            printf("%d/%d/%d\n",b[i][0],b[i][1],b[i][2]);
        }
        return 0;
    }
}