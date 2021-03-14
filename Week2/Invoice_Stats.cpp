#include<iostream>
#include <string.h>
#include <iomanip>
using namespace std;

// 描述
// 有一个小型的报账系统，它有如下功能：
// （1）统计每个人所报发票的总钱数
// （2）统计每类发票的总钱数
// 将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

// 输入
// 系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

// 输出
// 输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。

// 样例输入
// 1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
// 3 3 B 1 C 2 C 1
// 2 4 B 1 A 1 C 1 A 1

// 样例输出
// 1 6.00
// 2 4.00
// 3 4.00
// A 5.00
// B 3.00
// C 6.00

float getValuesForPerson(int id, int numInvoices, char categories[] , float values[]){
    float value = 0;
    for (int i = 0; i < numInvoices; i++){
        value += values[i];
    }
    return value;
}
float getValuesForA(int id, int numInvoices, char category[] , float values[]){
    float valueA = 0.0;
    for (int i = 0; i < numInvoices; i++){
        if (category[i] == 'A'){
            valueA += values[i];
        }
    }
    return valueA;
}

float getValuesForB(int id, int numInvoices, char category[] , float values[]){
    float valueB = 0.0;
    for (int i = 0; i < numInvoices; i++){
        if (category[i] == 'B'){
            valueB += values[i];
        }
    }
    return valueB;
}
float getValuesForC(int id, int numInvoices, char category[] , float values[]){
    float valueC = 0.0;
    for (int i = 0; i < numInvoices; i++){
        if (category[i] == 'C'){
            valueC += values[i];
        }
    }
    return valueC;
}
int main(){

    float valuesFromPerson[3] = {0, 0, 0}; // track the invoices values reported from person 1, 2, 3, the first value in array is from person 1
    float valuesFromCategory[3] = {0, 0, 0}; //track the invoices values reported from category A, B, C, the first value in array is from category A

    int id, numInvoices;
    float valuesOfA = 0;
    float valuesOfB = 0;
    float valuesOfC = 0;
    int index = 1;
    
    while (cin >> id >> numInvoices){
        
        //cout << "In while loop" <<endl;
        float values[numInvoices];
        char categories[numInvoices];
        for (int i = 0; i < numInvoices; i++){
            cin >> categories[i] >> values[i];
        }
        valuesFromPerson[id-1] = getValuesForPerson(id, numInvoices, categories, values);
        valuesOfA += getValuesForA(id, numInvoices, categories, values);
        valuesOfB += getValuesForB(id, numInvoices, categories, values);
        valuesOfC += getValuesForC(id, numInvoices, categories, values);
        //cout << "Current iteration: " << getValuesForA(id, numInvoices, categories, values) <<  ' ' << getValuesForB(id, numInvoices, categories, values) <<  ' ' << getValuesForC(id, numInvoices, categories, values) << endl;
        index++;
        if (index == 4){
            break;
        }
        //cout << index++ << endl;
    }
    for (int i = 0; i < 3; i++){
        cout << i + 1 << " " << fixed << setprecision(2) << valuesFromPerson[i] << endl;
    }
    cout << "A" << " " << fixed << setprecision(2) << valuesOfA << endl;
    cout << "B" << " " << fixed << setprecision(2) << valuesOfB << endl;
    cout << "C" << " " << fixed << setprecision(2) << valuesOfC << endl;
    return 0;
}