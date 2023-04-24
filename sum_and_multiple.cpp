#include <iostream>

int sum(int a[], int p,int q){
    if(p-q == 0) return a[p-1];
    return sum(a, p, (p+q)/2) + sum(a, (p+q)/2 + 1, q);
}

int bits(int a){
    int count = 0;
    while(a){
        a >>= 1;
        count ++;
    }

    return count;
}

int karatsuba(int a, int b, int n) {
    // 递归出口
    if (n == 1) {
        return a * b;
    }

    // 如果是奇数，可以直接加一变偶数方便处理，即相当于在a,b前加个0
    // karatsuba(101, 100, 3) == karatsuba(0101, 0100, 4)
    if(n%2 != 0) n++;

    int half_n = n / 2;

    int a1 = a >> half_n;
    int a0 = a - (a1 << half_n);
    int b1 = b >> half_n;
    int b0 = b - (b1 << half_n);
    int p1 = karatsuba(a1, b1, half_n);
    int p2 = karatsuba(a0, b0, half_n);
    int p3 = karatsuba(a1 + a0, b1 + b0, half_n);
    return p1 * (1 << n) + (p3 - p1 - p2) * (1 << half_n) + p2;
}

int max(int a,int b){
    return a>b?a:b;
}

int main() {

    int a[10] = {10,10,10,10,10,10,10,10,10,10};
    std::cout<<sum(a, 1, 10)<<std::endl;


    int num1 = 90, num2 = 520;
    int n = max(bits(num1), bits(num2));
//    if(n%2 != 0) n++;
    std::cout<<n<<std::endl;
    std::cout<<karatsuba(num1, num2, n)<<std::endl;

    return 0;
}
