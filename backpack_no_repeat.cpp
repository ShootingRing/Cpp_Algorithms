#include <iostream>
#include "matrix.h"

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

int knapsack(object obj[], int l, int packSize, matrix<int> res){
    //initialize
    for (int i = 0; i < l; ++i){
        for (int j = 1; j < packSize+1; ++j) {
            if(obj[i].weight > j){
                res.data[i+1][j] = res.data[i][j];
            }
            else {
                res.data[i+1][j] = max(res.data[i][j], res.data[i+1][j-obj[i].weight] + obj[i].value);
            }
        }
    }

    return res.data[l][packSize];
}

int doKnapsack(object obj[], int packSize, int length){

    matrix<int> res(length+1 < packSize+1? packSize+1:length+1,0);

    return knapsack(obj, length, packSize, res);
}

int main(){
    object obj[] = {
            object(4500, 4),
            object(5700, 5),
            object(2250,2),
            object(1100,1),
            object(6700,6)
    };

    int packSize = 8;

    cout<<"value:"<<doKnapsack(obj, packSize, 5)<<endl;
}