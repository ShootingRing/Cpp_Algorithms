#include <iostream>

using namespace std;

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

void tournament(int** res, int size, int start = 0){
    if(size == 1){
        return;
    }

    int l = size/2;

    tournament(res, l);
    tournament(res, l, start+l);

    matrix_equal<int>(res, res, l, start, start, start+l, start+l);
    matrix_equal<int>(res, res, l, start, start, start+l, start);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            res[start+l+i][start+j] = res[start+i][start+j] + l;
        }
    }
    matrix_equal<int>(res, res, l, start+l, start, start, start+l);


}

void tournament(const int* players, int** res, int size){
    res[0][0] = players[0];

    tournament(res, size);
}

int main()
{
    int players[8] = {1,2,3,4,5,6,7,8};
    int** res = new int*[8];
    for(int i = 0; i < 8; i++){
        res[i] = new int[8];
        for (int j = 0; j < 8; ++j) {
            res[i][j] = 0;
        }
    }
    tournament(players, res, 8);
    matrix_show<int>(res, 8);
    return 0;
}