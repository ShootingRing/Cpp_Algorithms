#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

/**
 *
 * @param a string a
 * @param b string b
 * @param la the length of string a
 * @param lb the length of string b
 * @param res res matrix
 * @return lev length
 * @brief Levenshtein
 */
int Levenshtein(const string& a, const string& b, int la, int lb, matrix<int> res){

    if(la == 0 || lb == 0) return (la == 0? lb:la);

    int sa = Levenshtein(a, b, la-1, lb, res) + 1;
    int sb = Levenshtein(a, b, la, lb-1, res) + 1;
    int sc = Levenshtein(a, b, la-1, lb-1, res) + ((a[la-1] == b[lb-1])? 0:1);

    res.data[la-1][lb-1] = min(sa, min(sb, sc));

    return res.data[la-1][lb-1];
}

/**
 *
 * @param a string a
 * @param b string b
 * @return lev length
 * @brief do Levenshtein, init the matrix and get length la, lb
 */
int doLeve(const string& a, const string&b){
    int la = (int)a.length(), lb = (int)b.length();

    matrix<int> res(la>lb?la:lb, 0);

    for (int i = 0; i < la; ++i) {
        res.data[i][0] = i;
    }

    for (int i = 0; i < lb; ++i) {
        res.data[0][i] = i;
    }

    return Levenshtein(a, b, la, lb, res);
}

int main(){
    string a = "kitte", b = "Sitti";

    cout<<doLeve(a, b)<<endl;
}