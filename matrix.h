//
// Created by 沃沃圈 on 2023/4/14.
//

#ifndef ALGORITHM_MATRIX_H
#define ALGORITHM_MATRIX_H

template<typename T>
class matrix {
public:
    T **data;
    int n;

    void init(int n);

    explicit matrix(int n);
    matrix(int n, T value);
};

template<typename T>
void matrix<T>::init(int n) {
    this->n = n;
    data = new T *[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new T[n];
    }
}

template<typename T>
matrix<T>::matrix(int n) {
    init(n);
}

template<typename T>
matrix<T>::matrix(int n, T value) {
    init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = value;
        }
    }
}

#endif //ALGORITHM_MATRIX_H
