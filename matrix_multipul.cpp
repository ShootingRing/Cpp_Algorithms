/*
 * @author Wiosier
 * @description 将矩阵分为A_lu,A_ld,A_ru,A_rd,B_lu,B_ld,B_ru,B_rd (left up->lu 以此类推), 为方便记为A_00,A_01,...
 *              根据Strassen's Matrix Multiplication算法算出M_1,M_2,...,M_7。
 *              M_1,M_2,...,M_7的计算也是矩阵乘法，进行递归；递归出口：单元素矩阵直接元素相乘。
 * @limit 输入矩阵均为n*n,其中n为2的幂
 * @tips 二维数组竖着的是x，横着的是y
 * */
#include <iostream>

using namespace std;

/*
 * @params T** A，T** B：两个n*n矩阵
 *         int n：矩阵边长
 *         T** res：存放结果
 *         int MINUS：是否为减法，MINUS=-1时为减法
 * @res res = A+B
 */
template<typename T>
void matrix_add(T** res, T** A, T** B, int n, int MINUS = 1){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = A[i][j] + B[i][j] * MINUS;
        }
    }
}

/*
 * @params T** from：n*n矩阵
 *         int fx, fy：from矩阵的起点
 *         int n：矩阵边长
 *         T** res：存放结果
 *         int rx, ry：res矩阵的起点
 * @res from赋值给res
 */
template<typename T>
void matrix_equal(T** res, T** from, int n, int fx = 0, int fy = 0, int rx = 0, int ry = 0){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i+rx][j+ry] = from[i+fx][j+fy];
        }
    }
}
/*
 * @params T** matrix：矩阵
 *         int n：边长
 * @res 输出
 */
template<typename T>
void matrix_show(T** matrix, int n){
    for(int i = 0; i < n; i++){
        cout<<"[";
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j];
            if(j != n-1) cout<<",";
        }
        cout<<"]";
        if(i != n-1) cout<<",";
        cout<<endl;
    }
}

/*
 * @params T** A，T** B：两个n*n矩阵
 *         int n：矩阵边长
 *         T** res：存放结果
 *         int rx,ry：res的起始位置
 * @res res = A*B
 */
template<typename  T>
void matrix_mul(T** res, T** A, T** B, int n, int rx = 0, int ry = 0){

    if(n == 1){
        res[rx][ry] = A[0][0] * B[0][0];
        return;
    }
    
    int l = n/2;

    T** A_00 = new T *[l];
    T** A_01 = new T *[l];
    T **A_10 = new T *[l];
    T **A_11 = new T *[l];
    
    T** B_00 = new T *[l];
    T** B_01 = new T *[l];
    T** B_10 = new T *[l];
    T** B_11 = new T *[l];
    
    T** C_00 = new T *[l];
    T** C_01 = new T *[l];
    T** C_10 = new T *[l];
    T** C_11 = new T *[l];

    T** temp1 = new T *[l];
    T** temp2 = new T *[l];

    T** M_1 = new T *[l];
    T** M_2 = new T *[l];
    T** M_3 = new T *[l];
    T** M_4 = new T *[l];
    T** M_5 = new T *[l];
    T** M_6 = new T *[l];
    T** M_7 = new T *[l];

    for (int i = 0; i < l; ++i) {
        A_00[i] = new T [l];
        A_01[i] = new T [l];
        A_10[i] = new T [l];
        A_11[i] = new T [l];

        B_00[i] = new T [l];
        B_01[i] = new T [l];
        B_10[i] = new T [l];
        B_11[i] = new T [l];

        C_00[i] = new T [l];
        C_01[i] = new T [l];
        C_10[i] = new T [l];
        C_11[i] = new T [l];
        
        temp1[i] = new T [l];
        temp2[i] = new T [l];
        
        M_1[i] = new T [l];
        M_2[i] = new T [l];
        M_3[i] = new T [l];
        M_4[i] = new T [l];
        M_5[i] = new T [l];
        M_6[i] = new T [l];
        M_7[i] = new T [l];
    }

    matrix_equal<T>(A_00, A, l);
    matrix_equal<T>(A_01, A, l, 0, l);
    matrix_equal<T>(A_10, A, l, l, 0);
    matrix_equal<T>(A_11, A, l, l, l);

    matrix_equal<T>(B_00, B, l);
    matrix_equal<T>(B_01, B, l, 0, l);
    matrix_equal<T>(B_10, B, l, l, 0);
    matrix_equal<T>(B_11, B, l, l, l);
    
    // calculate M_1
    matrix_add<T>(temp1, A_00, A_11, l);
    matrix_add<T>(temp2, B_00, B_11, l);
    matrix_mul<T>(M_1, temp1, temp2, l);
    
    // calculate M_2
    matrix_add<T>(temp1, A_10, A_11, l);
    matrix_mul<T>(M_2, temp1, B_00, l);
    
    // calculate M_3
    matrix_add<T>(temp2, B_01, B_11, l, -1);
    matrix_mul<T>(M_3, A_00, temp2, l);
    
    // calculate M_4
    matrix_add<T>(temp2, B_10, B_00, l, -1);
    matrix_mul<T>(M_4, A_11, temp2, l);
    
    // calculate M_5
    matrix_add<T>(temp1, A_00, A_01, l);
    matrix_mul<T>(M_5, temp1, B_11, l);
    
    // calculate M_6
    matrix_add<T>(temp1, A_10, A_00, l, -1);
    matrix_add<T>(temp2, B_00, B_01, l);
    matrix_mul<T>(M_6, temp1, temp2, l);

    // calculate M_7
    matrix_add<T>(temp1, A_01, A_11, l, -1);
    matrix_add<T>(temp2, B_10, B_11, l);
    matrix_mul<T>(M_7, temp1, temp2, l);

    // calculate C_00
    // M_1 + M_4 - M_5 + M_7 = (M_1 + M_4) + (M_7 - M_5)
    matrix_add<T>(temp1, M_1, M_4, l);
    matrix_add<T>(temp2, M_7, M_5, l, -1);
    matrix_add<T>(C_00, temp1, temp2, l);

    // calculate C_01
    // M_3 + M_5
    matrix_add<T>(C_01, M_3, M_5, l);

    // calculate C_10
    // M_2 + M_4
    matrix_add<T>(C_10, M_2, M_4, l);

    // calculate C_11
    // M_1 + M_3 - M_2 + M_6 = (M_1 + M_3) + (M_6 - M_2)
    matrix_add<T>(temp1, M_1, M_3, l);
    matrix_add<T>(temp2, M_6, M_2, l, -1);
    matrix_add<T>(C_11, temp1, temp2, l);

    matrix_equal<T>(res, C_00, l, 0, 0, rx, ry);
    matrix_equal<T>(res, C_01, l, 0, 0, rx, ry+l);
    matrix_equal<T>(res, C_10, l, 0, 0, rx+l, ry);
    matrix_equal<T>(res, C_11, l, 0, 0, rx+l, ry+l);
}

int main(){
    int n = 4;

    int** matrix1 = new int *[n];
    int** matrix2 = new int *[n];

    int** res1 = new int *[n];
    int** res2 = new int *[n];

    int** single1 = new int *[1];
    int** single2 = new int *[1];
    single1[0] = new int [1];
    single2[0] = new int [1];

    single1[0][0] = 5;
    single2[0][0] = 5;

    for (int i = 0; i < n; ++i) {
        matrix1[i] = new int [n];
        matrix2[i] = new int [n];
        res1[i] = new int [n];
        res2[i] = new int [n];
        for (int j = 0; j < n; ++j) {
            matrix1[i][j] = i + 1;
            matrix2[i][j] = i + 1;
        }
    }

    matrix_show<int>(matrix1, n);
    cout<<"----------"<<endl;

    matrix_add<int>(res1, matrix1, matrix2, n);
    matrix_show<int>(res1, n);
    cout<<"----------"<<endl;

    matrix_equal<int>(res2, res1, n);
    matrix_show<int>(res2, n);
    cout<<"----------"<<endl;

    matrix_mul<int>(res1, matrix1, matrix2, n);
    matrix_show<int>(res1, n);
    cout<<"----------"<<endl;

    matrix_mul<int>(res1, single1, single2, 1);
    matrix_show<int>(res1, 1);
    cout<<"----------"<<endl;

    /*
    [1,1,1,1],
    [2,2,2,2],
    [3,3,3,3],
    [4,4,4,4]
    ----------
    [2,2,2,2],
    [4,4,4,4],
    [6,6,6,6],
    [8,8,8,8]
    ----------
    [2,2,2,2],
    [4,4,4,4],
    [6,6,6,6],
    [8,8,8,8]
    ----------
    [10,10,10,10],
    [20,20,20,20],
    [30,30,30,30],
    [40,40,40,40]
    ----------
    [25]
    ----------

    进程已结束,退出代码0
     */
}