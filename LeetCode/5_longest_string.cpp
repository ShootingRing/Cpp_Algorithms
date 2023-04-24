#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief 暴力法 => 遍历
     *        leetCode 用例量 141/141
     *                 执行用时 12ms
     *                 内存消耗 10.9MB
     * @param s string
     * @return
     */
    [[nodiscard]] static string longestPalindrome(string s){
        int len, max = 0;
        string str;
        for(int i = 0; i<s.length();i++){
            len = 1;
            int j = 0;
            while(++j){
                if(i+j >= s.length() || i-j < 0){
                    j--;
                    break;
                }
                if(s[i+j] == s[i-j]) len+=2;
                else {
                    j--;
                    break;
                }
            }
            if(max < len){
                max = len;
                str = s.substr(i-j, len);
            }
        }

        max = 0;
        string str2;
        for(int i = 0; i<s.length()-1;i++){
            if(s[i] != s[i+1]) continue;
            len = 2;
            int j = 0;
            while(++j){
                if(i+j+1 >= s.length() || i-j < 0){
                    j--;
                    break;
                }
                if(s[i+j+1] == s[i-j]) len+=2;
                else {
                    j--;
                    break;
                }
            }
            if(max < len){
                max = len;
                str2 = s.substr(i-j, len);
            }
        }
        return str.length() > str2.length()? str : str2;
    }

    /**
     * @brief 动态规划解法 - 伪(这个反而更慢了)
     * @param s string
     * @return
     */
    [[nodiscard]] static string longestPalindromeDynamic(string s){
        //TODO Dynamic longestPalindrome method
        int len = s.length(), step = len;
        if(len == 1) return s;
        if(len == 2 & s[0] == s[1]) return s;
        string res;
        while(step) {
            for (int i = 0; i < len; i++) {
                if(i + step -1 >= len) break;
                if (s[i] != s[i + step - 1]) continue;
                res = s.substr(i, step);
                string next = s.substr(i+1, step-2);
                if(next == longestPalindromeDynamic(next)){
                    step = 1;
                    break;
                }
            }
            step--;
        }

        return res;
    }

    /**
 * @brief 动态规划解法
 * @param s string
 * @return
 */
    [[nodiscard]] static string longestPalindromeRealDynamic(string s){
        //TODO Dynamic longestPalindrome method
        //res[i][j] 表示 xi, xi+1, xi+2, ..., xj 是否为回文串
        //res[i][j] = res[i+1][j-1] & s[i] == s[j]
        //if(len == 1) res[i][j] = true
        //if(len == 2) res[i][j] = s[i] == s[j]
        int size = s.size();
        if(size < 2){
        return s;
        }
        
        vector<vector<bool>> res(size, vector<bool>(size));

        for (int i = 0; i < size; ++i) {
            res[i][i] = true;
        }

        int begin = 0;
        int maxLen = 1;
        for (int L = 2; L <= size; ++L) {
            for (int i = 0; i < size; ++i) {
                int j = i + L - 1;
                if(j >= size){
                    break;
                }

                if(s[i] != s[j]){
                    res[i][j] = false;
                }else{
                    if(L < 3){
                        res[i][j] = true;
                    }else{
                        res[i][j] = res[i+1][j-1];
                    }
                }

                if(res[i][j] && maxLen<L){
                    maxLen = L;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

    /**
     * Manacher算法：待写
     * https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/ 方法三
     */
};

int main(){
    string str;
    while(cin>>str){
        cout<<Solution::longestPalindrome(str)<<endl;
        cout<<Solution::longestPalindromeDynamic(str)<<endl;
        cout<<Solution::longestPalindromeRealDynamic(str)<<endl;
    }

}