#include <iostream>
using namespace std;

//Problem statement: 细菌实验分组: 有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，
//                   A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，
//                   请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。 
//                   细菌繁殖能力（繁殖率）的量化标准为一个小时内细菌数量增长的比例（繁殖率 = 一小时后细菌数量 /  原本细菌数量）。
//                   两个亚种繁殖能力差异很大，这意味着对于任意两个同种细菌培养皿的繁殖率的测量值之间的差异要小于任意两个异种细菌培养皿繁殖率的测量值之间的差异。

//Input: 输入有多行，第一行为整数n（n≤100），表示有n个培养皿。 
//       其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。假设试验没有误差。

//Output: 输出有多行： 
//        第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。 
//        然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。

//Example input: 5
//               1 10 3456
//               2 10 5644
//               3 10 4566
//               4 20 234
//               5 20 232

//Example output: 3
//                1
//                3
//                2
//                2
//                5
//                4

int main(){
    int n; //n is the number of bateria containers
    int id[100]; //the array to store the IDs of each bateria container
    double rate[100]; //the array to store the growth rate of bacteria in each container

    cin >> n;

    //calculate growth rate for each bateria container
    for (int i = 0; i < n; i++){
        int initial, final;
        cin >> id[i] >> initial >> final;
        rate[i] = (double) final / initial;
    }

    //sort all bateria containers based on their growth rate
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (rate[j + 1] > rate[j]){

                int tempID = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempID;

                double tempRate = rate[j];
                rate[j] = rate[j + 1];
                rate[j + 1] = tempRate;
            }
        }
    }

    //find the maximum rate difference between the same type bateria.
    //bateria rates are sorted already so just need to track maximum rate diff between
    //two neiboring bateria containers. This is where bactera array goes from the first type to the second type 
    //(bacteria A and B have very different growth rate)
    double maxDiff = 0;
    int maxDiffIndex = 0;
    for (int i = 0; i < n - 1; i++){
        double diff = rate[i] - rate[i + 1];
        if (maxDiff < diff){
            maxDiff = diff;
            maxDiffIndex = i;
        }
    }

    //otuput the type A bateria (the one that has larger growth rate)
    cout << maxDiffIndex + 1 << endl;
    for (int i = maxDiffIndex; i >= 0; i--){
        cout << id[i] << endl;
    }

    //otuput the type B bateria (the one that has smaller growth rate)
    cout << n - maxDiffIndex - 1 << endl;
    for (int i = n - 1; i >= maxDiffIndex + 1; i--){
        cout << id[i] << endl;
    }
    return 0;
}