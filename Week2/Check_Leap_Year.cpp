#include<iostream>
#include <string.h>
using namespace std;

// 描述
// 判断某年是否是闰年。

// 输入
// 输入只有一行，包含一个整数a(0 < a < 3000)

// 输出
// 一行，如果公元a年是闰年输出Y，否则输出N

// 样例输入
// 2006

// 样例输出
// N

int main(){
    int year;
    cin >> year;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        cout << 'Y' << endl;
    }
    else{
        cout << 'N' << endl;
    }
    return 0;
}
