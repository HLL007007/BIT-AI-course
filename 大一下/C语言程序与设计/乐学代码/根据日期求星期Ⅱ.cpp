# include<stdio.h>
int is_leapYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	} 
	else return 0;
}
int main(){
	int year , month , day;
	int total = 0;
	scanf("%d %d %d",&year,&month,&day);
    if (month < 1 || month > 12 ){
        printf("month is error.\n");
        return 0;
    }
    if (day < 1 || day > 31){
        printf("day is error.\n");
        return 0;
    }
    if (month == 2){
        if(is_leapYear(year)){
            if (day > 29){
                printf("day is error.\n");
                return 0;
            }
        }
        else {
            if (day > 28){
                printf("day is error.\n");
                return 0;
            }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if (day > 31){
            printf("day is error.\n");
            return 0;
        }
    }
    else {
        if (day > 30){
            printf("day is error.\n");
            return 0;
        }
    }
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
	printf("%d\n",ans);
	return 0;
}