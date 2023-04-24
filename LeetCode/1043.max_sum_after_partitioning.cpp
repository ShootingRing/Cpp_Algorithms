#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * k = 3
 * [1]  1
 * [1, 15]  15*2
 * [1, 15, 7] 15*3
 * [1, 15, 7, 9] 9 + dp[2] / 9*2 + dp[1] / 15*3 + dp[0]
 *
 * [1, 15, 7, 9, 2] 15*3 + 9*2
 * [1, 15, 7, 9, 2, 5] 15*3 + 9*3
 * [1, 15, 7, 9, 2, 5, 10] 15*3 + 9 + 10*3
 */

/**
 * k = 4
 * [1]  1
 * [1, 4] 4*2
 * [1, 4, 1] 4*3
 * [1, 4, 1, 5] 5*4
 * [1, 4, 1, 5, 7] 5*4 + 7 / 7*4 + 1 => 7*4 + 1
 * [1, 4, 1, 5, 7, 3]
 */

class Solution {
public:
    [[nodiscard("missing int !")]] static int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());

        int maxNum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if(i < k){
                maxNum = max<int>(maxNum, arr[i]);
                dp[i] = maxNum * (i+1);
            }else{
                int maxRes = 0, maxTemp = 0;
                for (int j = i; j >= 0 && i-j+1 <= k; --j) {
                    maxTemp = max<int>(arr[j], maxTemp);

                    if(j-1<0){
                        maxRes = max<int>(maxRes, maxTemp*(i-j+1));
                    }else {
                        maxRes = max<int>(maxRes, maxTemp*(i-j+1)+dp[j-1]);
                    }
                }
                dp[i] = maxRes;
            }
        }

        return dp[arr.size()-1];
    }
};

int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout<<Solution::maxSumAfterPartitioning(arr, k)<<endl;
}