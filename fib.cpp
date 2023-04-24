#include<iostream>
#include<cstdio>
#define long long int

using namespace std;

void Matrix_Mul(int (&m)[2][2],int (&n)[2][2])
{
    int tmp[2][2];
    for(int i=0; i<2;i++)
    {
        for(int j=0; j<2; j++)
        {
            tmp[i][j] = 0;
            for(int k=0; k<2; k++)
                tmp[i][j] += m[i][k] * n[k][j];
        }
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            m[i][j] = tmp[i][j];
}

int Fibonacci(int n)
{
    int result[2][2] = {
            {1,0},
            {0,1}
    };  //单位矩阵

    int a[2][2] = {
            {1,1},
            {1,0}
    };

    while(n)
    {
        if(n & 1) //相当于n % 2 == 1
            Matrix_Mul(result,a);
        n = n >> 1;    //相当于n /= 2
        Matrix_Mul(a,a);
    }
    return result[0][1];
}



int main()
{
    int n;
    cout<<"which:";
    cin>>n;
    printf("%dth:%d",n,Fibonacci(n));
    return 0 ;
}
