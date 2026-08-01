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
    // 1900.1.1 -- 1
    for(int i = 1900 ; i < year ; i++){
  		if (is_leapYear(i)) total += 366;
		else total += 365;
	}
	// for (int i = 1 ; i < month ; i++){
	// 	if (i == 2){
	// 	   	if(is_leapYear(year)){
	// 			  total += 29;
  	// 		}
	//  	    else total += 28;
	// 	}
	// 	else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) total += 31;
	// 	else total += 30;
	// }
	switch(month - 1){
		case 12: total += 31;
		case 11: total += 30;
		case 10: total += 31;
		case 9: total += 30;
		case 8: total += 31;
		case 7: total += 31;
		case 6: total += 30;
		case 5: total += 31;
		case 4: total += 30;
		case 3: total += 31;
		case 2: if(is_leapYear(year)) total += 29;
				else total += 28;
		case 1: total += 31;
	}
	total += day;
	int ans = total % 7;
	printf("%d\n",ans);
	return 0;
}