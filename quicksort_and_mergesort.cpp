#include <iostream>

template<typename T>
void swap(T& a, T& b){
    a = a+b;
    b = a-b;
    a = a-b;
}

template<typename T>
void quick_sort(T A[], int start, int end){
    if(start >= end) return;

    int base = A[start];
    int i = start, j = end;

    while(i < j){

        while(A[j] >= base && i < j) j--;
        while(A[i] <= base && i < j) i++;

        if(i >= j) swap(A[i], A[start]);
        else swap(A[i], A[j]);
    }

    quick_sort(A, start, i-1);
    quick_sort(A, i+1, end);
}

template<typename T>
void merge_sort(T A[], T temp[], int p, int q) {
    if(p>=q) return;

    int start1 = p;
    int end1 = (q+p)/2;
    int start2 = end1 + 1;
    int end2 = q;

    merge_sort(A, temp, start1, end1);
    merge_sort(A, temp,start2, end2);

    int i = p;

    while (start1 <= end1 && start2 <= end2)
        temp[i++] = A[start1] < A[start2] ? A[start1++] : A[start2++];
    while (start1 <= end1)
        temp[i++] = A[start1++];
    while (start2 <= end2)
        temp[i++] = A[start2++];

    for (i = p; i <= q; i++)
        A[i] = temp[i];
}

int main(){

    int A[] = {7, 5, 8, 4, 2, 3, 9, 6, 1, 0};
    int temp[10];

    merge_sort(A, temp, 0, 9);

    for(auto &c : A){
        std::cout<<c<<std::endl;
    }

    std::cout<<"------------------"<<std::endl;

    int B[] = {7, 5, 8, 4, 2, 3, 9, 6, 1, 0};

    quick_sort(B, 0, 9);

    for(auto &c : B){
        std::cout<<c<<std::endl;
    }
}
