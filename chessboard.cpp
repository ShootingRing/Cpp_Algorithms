#include <iostream>

using namespace std;
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
 * @params int x,y : coordinate
 *         int n : length of matrix
 * @description calculate the special block's location (0 left up / 1 right up / 2 left down / 3 right down)
 */
int index(int x, int y, int special_x, int special_y, int n){
    int a = 0, b = 0;

    a = special_x-x<n/2 ? 0 : 2;
    b = special_y-y<n/2 ? 0 : 1;

    return a + b;
}

/*
 * @params bool** board : chessboard
 *         int x,y : start point
 *         int special_x,special_y : special grid
 *         int size : size
 */
void chessBoard(bool** board, int x, int y, int special_x, int special_y, int size) {
    // exit
    if(size == 1) return;

    int s = size/2;

    switch (index(x, y, special_x, special_y, size)) {
        case 0:
            board[x+s-1][y+s] = true;
            board[x+s][y+s-1] = true;
            board[x+s][y+s] = true;
            chessBoard(board, x, y, special_x, special_y, s);
            chessBoard(board, x, y+s, x+s-1, y+s, s);
            chessBoard(board, x+s, y, x+s, y+s-1, s);
            chessBoard(board, x+s, y+s, x+s, y+s, s);
            break;
        case 1:
            board[x+s-1][y+s-1] = true;
            board[x+s][y+s-1] = true;
            board[x+s][y+s] = true;
            chessBoard(board, x, y, x+s-1, y+s-1, s);
            chessBoard(board, x, y+s, special_x, special_y, s);
            chessBoard(board, x+s, y, x+s, y+s-1, s);
            chessBoard(board, x+s, y+s, x+s, y+s, s);
            break;
        case 2:
            board[x+s-1][y+s-1] = true;
            board[x+s-1][y+s] = true;
            board[x+s][y+s] = true;
            chessBoard(board, x, y, x+s-1, y+s-1, s);
            chessBoard(board, x, y+s, x+s-1, y+s, s);
            chessBoard(board, x+s, y, special_x, special_y, s);
            chessBoard(board, x+s, y+s, x+s, y+s, s);
            break;
        case 3:
            board[x+s-1][y+s-1] = true;
            board[x+s-1][y+s] = true;
            board[x+s][y+s-1] = true;
            chessBoard(board, x, y, x+s-1, y+s-1, s);
            chessBoard(board, x, y+s, x+s-1, y+s, s);
            chessBoard(board, x+s, y, x+s, y+s-1, s);
            chessBoard(board, x+s, y+s, special_x, special_y, s);
            break;
    }
}

int main() {
    bool **board = new bool *[4];
    for (int i = 0; i < 4; ++i) {
        board[i] = new bool [4];
        for (int j = 0; j < 4; ++j) {
            board[i][j] = false;
        }
    }

    chessBoard(board, 0, 0, 1, 1, 4);
    matrix_show<bool>(board, 4);
}

/*
[1,1,1,1],
[1,0,1,1],
[1,1,1,1],
[1,1,1,1]

进程已结束,退出代码0
 */