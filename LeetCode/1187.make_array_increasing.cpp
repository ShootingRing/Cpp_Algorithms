#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        for (auto &c: arr2) {
            cout<<c<<",";
        }
        cout<<endl;

        vector<int> dp(arr1.size());
        dp[0] = 0;

        for (int i = 1; i < arr1.size(); ++i) {

            int cnt = 0;
            for (int j : arr2) {
                if(arr1[i] > j) break;
                cnt++;
            }
            if(arr1[i] > arr1[i-1]){
                dp[i] = dp[i-1];
            }
            else if(arr1[i] <= arr1[i-1]){
                if(cnt < i){
                    dp[i] = dp[i-1] + 1;
                }
                else {
                    dp[i] = min(dp[i-1] + 1, i);
                }
            }
        }

        return dp[arr1.size() - 1];
    }
};

int main(){
    vector<int> arr1 = {19,18,7,4,11,8,3,10,5,8,13};
    vector<int> arr2 = {13,16,9,14,3,12,15,4,21,18,1,8,17,0,3,18};

    cout<<endl;
    cout<<Solution::makeArrayIncreasing(arr1, arr2)<<endl;
    /**
        [19, 18, 7, 4, 11, 8, 3,  10, 5,  8,  13]
         0'  1'  3' 4  11  12' 13' 14' 15' 16' 17'
        0 1 3 4 8 9 12 13 14 15 16 17 18 21

        arr1[i] <= arr1[i-1] && arr2中比arr1[i]小的数的个数 >= i:
        1. arr1[i]不换:
            dp[i] = i;
        2. arr1[i]换:
            dp[i] = dp[i-1] + 1;
        取最小值

        arr1[i] > arr1[i-1]:
        arr1[i]不换:
            dp[i] = dp[i-1];



     */

    /**
     * dp[i][j] 前i个换了j个能不能变成严格递增
     *
     */
}