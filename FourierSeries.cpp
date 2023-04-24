#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

double PI = 3.141592653589793238460;

//fast fourier transform
/*
 * @author : Wiosier(@沃沃圈)
 *
 * three steps:
 *      - Evaluation : from Coeff to Value
 *      - Interpolation : from Value to Coeff
 *      - Multiplication : Multiply Coeffs
 *
 *      - Evaluation :
 *          - by using FFT(Coeffs) return Values
 *          - using points to calculate values, so we need to select axis x :
 *              - w = e^((2*pi*i)/n), i is complex number not a var
 *              - w is (z^n = 1)'s solutions, w^j + w^(j+n/2) = 0
 *              - so (w^j)^2 = (w^(j+n/2))^2
 *              - x = [w^0, w^1, w^2, ..., w^n-1]
 *          - matrix of Values(actually it is a vector or list) = DFT matrix * matrix of Coeffs(also a vector or list)
 *              - matrix of Coeffs : input
 *              - DFT :
 *                  - [ 1, 1, 1, 1                              ]
 *                  - [ 1, w, w^2, w^3                          ]
 *                  - [ ...                                     ]
 *                  - [ 1, w^(n-1), w^2(n-1), ..., w^(n-1)(n-1) ]
 *          -  just put this matrix form away, back to multinomial :
 *              - P(x) = P_o(x^2) + xP_e(x^2)
 *              - P(-x) = P_o(x^2) - xP_e(x^2)
 *              - so when we know P_0 and P_e, we know two P
 *              - to solve P_o and P_e :
 *                  -recursion :
 *                      - FFT(P_o's Coeffs) and FFT(P_e's Coeffs)
 *                      - when n==1 just return Coeffs
 *          - so we know P(x) AKA Values
 *
 *      -Interpolation :
 *          - by using IFFT(Values) return Coeffs
 *          - w -> w^(-1)
 *          - a[i] -> a[i]/n
 */

complex<double> omega(int i, int n, bool isReverse){
    complex<double> r {cos(2*PI*i/n), (isReverse? -1:1)*sin(2*PI*i/n)};
    return r;
}

/*
 * @params
 */
void fft(complex<double>* coeffs, int size, bool isReverse = false){
    if(size == 1){
        return;
    }

    //divide coeffs to even and odd
    auto* even = new complex<double> [size/2];
    auto* odd = new complex<double> [size/2];

    for (int i = 0; i < size; ++i) {
        if(i & 1){ // If i is odd or not
            odd[i/2] = coeffs[i];
        }else{
            even[i/2+1] = coeffs[i];
        }
    }

    for (int i = 0; i < size/2; ++i) {
        coeffs[i] = even[i];
        coeffs[i + size/2] = odd[i];
    }

    fft(coeffs, size/2, isReverse);
    fft(coeffs + size/2, size/2, isReverse);

    for (int i = 0; i < size/2; ++i) {
        complex<double> t = omega(i, size, isReverse);
        complex<double> temp {static_cast<double>(isReverse? 2:1), 0};
        coeffs[i] = (even[i] + t*odd[i])/temp;
        coeffs[i + size/2] = (even[i] - t*odd[i])/temp;
    }
}

void ifft(complex<double>*& coeffs, int size){
    fft(coeffs, size, true);
}

using namespace std;

int main(){
    auto a = new complex<double> [8];
    auto b = new complex<double> [8];

    for (int i = 0; i < 8; ++i) {
        //some Coeffs sample
        a[i] = complex<double> {static_cast<double>(i), 0};
        b[i] = complex<double> {static_cast<double>(i), 0};
    }

    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
        cout << b[i] << endl;
    }
    cout << "------------------" << endl;

    //get Values
    fft(a, 8);
    fft(b, 8);

    //Multiply Values
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
        cout << b[i] << endl;
        a[i] = a[i] * b[i];
        cout << a[i] << endl;
        cout << "------------------" << endl;
    }

    //get Coeffs
    ifft(a, 8);

    //print Coeffs
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
    }

    //delete
    delete[] a;
    delete[] b;
    return 0;
}
