#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxSatisfaction(vector<int>& satisfaction) {
        int len = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int res = 0, add = 0;
        for (int i = 0; i < len; ++i) {
            int temp = res;
            add += satisfaction[i];
            if(add > 0) res += add;
            else {
                break;
            }
        }
        return res;
    }
};

int main(){
    vector<int> a = {4, 3, 2};
    cout<<Solution::maxSatisfaction(a)<<endl;
}