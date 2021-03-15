#include<iostream>
#include <string.h>
using namespace std;

// 描述
// 输入一个句子（一行），将句子中的每一个单词翻转后输出。

// 输入
// 只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。

// 这道题请用cin.getline输入一行后再逐个单词递归处理。

// 输出
// 翻转每一个单词后的字符串，单词之间的空格需与原文一致。

// 样例输入
// hello    world.

// 样例输出
// olleh    .dlrow
const int length = 10;
char str[length];

int reverse(int i){
    if(str[i] == ' ' || str[i] == '\0'){ //when hit a space, return -1
        return -1;
    }
    
    reverse (i + 1);
    cout << str[i];
    return -1;
    
}

int main(){
    int printedFlag = false; //track if current word has been reversed and printed
    cin.getline(str, length);
    for (int i = 0; i < length; i++){
        if (str[i] != ' ' && printedFlag == false){
            reverse(i);
            printedFlag = true;
            continue;
        }
        if (str[i] == ' '){
            printedFlag = false; //reset the print flag when hit a space char
            cout << ' ';
            continue;
        }
        if (str[i] == '\0'){ //when hit the end of the valid string, break
            break;
        }

    }
    //cout << str << endl;
    return 0;
}