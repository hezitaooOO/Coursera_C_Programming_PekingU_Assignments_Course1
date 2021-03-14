#include<iostream>
#include <string.h>
using namespace std;

// 描述
// 我国有4大淡水湖。
// A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
// B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
// C说：洪泽湖最小，洞庭湖第三。
// D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
// 已知这4个湖的大小均不相等，4个人每人仅答对一个，
// 请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。

// 输入
// 无。

// 输出
// 输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。

// 样例输入
// (无)

// 样例输出
// 3(样例输出仅供格式参考，此题只有一个解)
void findLakes(){
    bool a, b, c, d; // represent the trueness of statements from person A, B, C, D
    //iteartare through all possible four lakes ranking
    for (int pyh = 1; pyh <= 4; pyh++){
        for (int dth = 1; dth <= 4; dth++){
            for (int th = 1; th <= 4; th++){
                for (int hzh = 1; hzh <= 4; hzh++){
                    if ((pyh - dth)*(pyh - th)*(pyh - hzh)*(dth - th)*(dth - hzh)*(th - hzh) != 0){ //if four lakes have have different rankings
                        a = (dth == 1) + (hzh == 4) + (pyh == 3) == 1;//A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
                        b = (hzh == 1) + (dth == 4) + (pyh == 2) + (th == 3) == 1;//B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
                        c = (hzh == 4) + (dth == 3) == 1;//C说：洪泽湖最小，洞庭湖第三。
                        d = (pyh == 1) + (th == 4) + (hzh == 2) + (dth == 3) == 1;//D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
                        if (a == b == c == d == 1){ //如果4个人每人仅答对一个
                            cout << pyh << endl;
                            cout << dth << endl;
                            cout << th << endl;
                            cout << hzh << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    findLakes();
    return 0;
}