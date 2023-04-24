#include <iostream>
#include <cstring>

using namespace std;

// pair => max, min
/*
 * @params int a[] : list
 *         int p,q : start and end
 *         int defeat[] : defeat list
 *         int &i : defeat[i] is "empty"
 * @return smallest
 */
int Compare(int a[], int defeat[], int p, int q, int &i){
    if(q - p + 1 <= 2){
        if(a[p] > a[q]){
            defeat[i] = a[p];
            i++;
            return a[q];
        }
        else{
            defeat[i] = a[q];
            i++;
            return a[p];
        }
    }

    int min1 = Compare(a, defeat, p ,(p+q)/2, i);
    int min2 = Compare(a, defeat, (p+q)/2+1, q, i);

    int min;
    min = min1 < min2 ? min1 : min2;

    return min;
}

/*
 * @params int a[] : list
 *         int p,q : start and end
 *         int defeat[] : defeat list
 * @return secondSmallest
 */
int secondSmallest(int a[], int defeat[], int p, int q){
    int i = 0;
    int min = Compare(a, defeat, p, q, i);
    i = 0;
    return Compare(defeat, a, p, q, i);
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8};
    int defeat[8];
    memset(defeat, 1, sizeof(defeat));

    cout<<secondSmallest(a, defeat, 0, 7)<<endl;
}

/*
2

进程已结束,退出代码0
 */