#include <iostream>
#include <algorithm>
using namespace std;

class object{
public:
    int value;
    int weight;

    object(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

int knapsack(object obj[], int l, int packSize){
    int res[packSize+1];
    fill_n(res, packSize+1, 0);

    for (int i = 0; i < l; ++i){
        for (int j = obj[i].weight; j <= packSize; ++j) {
            res[j] = max(res[j], res[j-obj[i].weight] + obj[i].value);
        }
    }

    return res[packSize];
}

int main(){
    object obj[] = {
            object(4500, 4),
            object(5700, 5),
            object(2250, 2),
            object(1100, 1),
            object(6700, 6)
    };

    int packSize = 8;

    cout<<"value:"<<knapsack(obj, 5, packSize)<<endl;
}