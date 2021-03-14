#include<iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

// 描述
// 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,
// 真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。
// 读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，
// 也不晚于2999-12-30。

// 输入
// 输入仅一行，格式为yyyy-mm-dd的日期。

// 输出
// 输出也仅一行，格式为yyyy-mm-dd的日期

// 样例输入
// 2010-07-05

// 样例输出
// 2010-07-06

// 提示
// 闰年的标准：

// (1)普通年能被4整除且不能被100整除的为闰年。（如2004年就是闰年,1901年不是闰年）
// (2)世纪年能被400整除的是闰年。(如2000年是闰年，1100年不是闰年)
// (3)可以利用一个字符变量吃掉输入的短横线（减号），输出时请活用setfill和setw 控制符.

const int normalYearDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int leapYearDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year){
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return true;;
    }
    else{
        return false;;
    }
}

int yearOfNextDay(int year, int month, int day){
    if (month == 12 && day == 31){ //if the day is the last day(Dec 31st) of that year, then return the next year
        return year + 1;
    }
    return year;
}

int monthOfNextDay(int year, int month, int day){
    if (isLeapYear(year)){
        if (day == leapYearDays[month - 1]){ //if the day is the last day of that month in a leap year, then return the next month
            if (month < 12){
                return month + 1;
            }
            else {
                return 1;
            }
            
        }
    }
    else{
        if (day == normalYearDays[month - 1]){ //if the day is the last day of that month in a normal year, then return the next month
            if (month < 12){
                return month + 1;
            }
            else {
                return 1;
            }
        }
    }
    return month;
}

int dayOfNextDay(int year, int month, int day){
    if (isLeapYear(year)){
        if (day == leapYearDays[month - 1]){ //if the day is the last day of that month in a leap year, then return 1 (first day of the month)
            return 1;
        }
    }
    else{
        if (day == normalYearDays[month - 1]){ //if the day is the last day of that month in a normal year, then return 1 (first day of the month)
            return 1;
        }
    }
    return day + 1;
}

int main(){
    string str;
    cin >> str;
    int year = stoi(str.substr(0, 4));
    string monthStr = str.substr(5, 2);
    int month, day;
    if (monthStr.find("0") == 0){
        month = stoi(monthStr.substr(1));
    }
    else{
        month = stoi(monthStr);
    }
    string dayStr = str.substr(8, 2);

    if (dayStr.find("0") == 0){
        day = stoi(dayStr.substr(1));
    }
    else{
        day = stoi(dayStr);
    }


    //cout << str << endl;
    int yearTomorrow = yearOfNextDay(year, month, day);
    int monthTomorrow = monthOfNextDay(year, month, day);
    int dayTomorrow = dayOfNextDay(year, month, day);

    cout << yearTomorrow << "-";
    if (monthTomorrow < 10){
        cout << 0;
    }
    cout << monthTomorrow << "-";
    if (dayTomorrow < 10){
        cout << 0;
    }
    cout << dayTomorrow << endl;
}
