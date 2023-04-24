#include <iostream>
#include "matrix.h"

/**
 *
 * @param n is the exponential of binomial + 1
 * @param res is the result matrix
 */
void coefficient(int n, matrix<int> res){
    for (int i = 0; i < n; ++i) {
        res.data[i][0] = 1;
    }
    res.data[1][1] = 1;

    for (int i = 2; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            res.data[i][j] = res.data[i-1][j-1] + res.data[i-1][j];
        }
    }
}

/**
 *
 * @param n is the exponential of binomial
 * @return the result matrix
 */
matrix<int> cal_coefficient(int n){
    matrix<int> res(n+1, 0);
    coefficient(n+1, res);

    return res;
}

int main(){
    matrix<int> res = cal_coefficient(2);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << res.data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}