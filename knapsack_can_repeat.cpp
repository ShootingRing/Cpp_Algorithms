#include<iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include<map>
using namespace std;
/**
 * 0-1背包问题
 */
int main(int argc,char *agrv[])
{
    // 假设有这几个东西
    int val[3]{ 0 };
    int weight[3]{ 0 };
    int n = 0;
    int m = sizeof weight / sizeof(int);

    cout << "values:";
    cin >> val[0] >> val[1] >> val[2];
    cout << "weights:";
    cin >> weight[0] >> weight[1] >> weight[2];
    cout << "knapsack:";
    cin >> n;
    int** table = new int*[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        table[i] = new int[n + 1]{0};
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (weight[i - 1] > j)
            {
                table[i][j] = table[i - 1][j];
            }
            else {
                table[i][j] = max(table[i - 1][j], val[i - 1] +
                                                   table[i][j - weight[i - 1]]);
            }
        }
    }
    for (int i = 0; i < m + 1; i ++ )
    {
        for (int j = 0; j < n + 1; j ++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout<<table[m][n]<<endl;
    for (int i = 0; i < m + 1; i++)
    {
        delete table[i];
    }
    delete table;
    system("pause");
    return 0;
}
/**
values:1500 3000 2000
weights:1 4 3
knapsack:4
0 0 0 0 0
0 1500 3000 4500 6000
0 1500 3000 4500 6000
0 1500 3000 4500 6000
6000
*/