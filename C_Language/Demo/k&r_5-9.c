int day_of_year(int year,int month ,int day);
void month_day(int year, int yearday,int *pmonth,int *pday);

int normal_year[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int leap_year[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int *month_day_lst[2] = {normal_year,leap_year};

int day_of_year(int year,int month ,int day){
    int i ,leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1;i < month;++i){
        day += month_day_lst[leap][i];
    }
    return day;
}

void month_day(int year, int yearday,int *pmonth,int *pday){
    int i ,leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1;yearday > month_day_lst[leap][i];i++) {
        yearday -= month_day_lst[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}