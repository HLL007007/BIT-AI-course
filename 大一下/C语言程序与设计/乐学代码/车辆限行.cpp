#include <stdio.h>

// 判断是否为闰年
int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算从公元 1 年 1 月 1 日到指定日期的总天数
int get_days(int year, int month, int day) {
    int days = 0;
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 累加之前年份的天数
    for (int i = 1; i < year; i++) {
        days += 365 + is_leap(i);
    }
    
    // 累加当年之前月份的天数
    for (int i = 1; i < month; i++) {
        days += month_days[i];
        // 如果是闰年且过了2月，多加1天
        if (i == 2 && is_leap(year)) {
            days++;
        }
    }
    
    // 累加当月天数
    days += day;
    
    return days;
}

int main() {
    int y, m, d;
    // 定义限号组合数组，按规律排好序
    const char *pairs[] = {"5 and 0", "1 and 6", "2 and 7", "3 and 8", "4 and 9"};
    
    // 读取输入的年月日
    if (scanf("%d %d %d", &y, &m, &d) == 3) {
        
        // 计算基准日期（2012年4月9日）和目标日期的总天数
        int base_days = get_days(2012, 4, 9);
        int target_days = get_days(y, m, d);
        
        // 算出差值（间隔天数）
        int diff = target_days - base_days;
        
        // 判断星期几 (0=周一, 1=周二, 2=周三, 3=周四, 4=周五, 5=周六, 6=周日)
        int weekday = diff % 7;
        
        // 周六和周日不限行
        if (weekday == 5 || weekday == 6) {
            printf("Free.\n");
        } else {
            // 计算当前处于第几个轮换周期 (91天 = 13周)
            int period = diff / 91;
            
            // 核心推导公式
            int index = (3 + weekday - (period % 5) + 5) % 5;
            
            // 输出限行尾号
            printf("%s.\n", pairs[index]);
        }
    }
    
    return 0;
}