#include <iostream>

using namespace std;

// pair => max, min
/*
 * @params T a[] : list
 *         int p,q : start and end
 */
template<typename T>
pair<T, T> Compare(T a[], int p, int q){
    if(q - p + 1 <= 2){
        if(a[p] > a[q])
            return make_pair(a[p], a[q]);
        else
            return make_pair(a[q], a[p]);
    }

    pair<T, T> pair1 = Compare(a, p ,(p+q)/2);
    pair<T, T> pair2 = Compare(a,(p+q)/2+1, q);

    T max, min;
    max = pair1.first > pair2.first ? pair1.first : pair2.first;
    min = pair1.second < pair2.second ? pair1.second : pair2.second;

    return make_pair(max, min);
}

int main(){
    int a[] = {5,8,7,6,1,2,
               54,568,153,12,87,
               354,213,1,2,56,
               87,954,1,23,45
                };
    pair<int, int> maxAndMin = Compare<int>(a, 0, 20);

    cout<<maxAndMin.first<<" "<<maxAndMin.second;
}

/*
954 1
进程已结束,退出代码0
 */