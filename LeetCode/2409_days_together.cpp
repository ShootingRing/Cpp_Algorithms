#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    [[nodiscard]] static vector<int> splitDate(const string &date) {
        size_t slicePos = date.find('-');
        string arrive_month = date.substr(0 , slicePos);
        string arrive_day = date.substr(slicePos+1, date.length() - slicePos-1);
        return vector<int>{stoi(arrive_month), stoi(arrive_day)};
    }

    /**
     *
     * @param arriveAlice
     * @param leaveAlice
     * @param arriveBob
     * @param leaveBob
     * @brief find the latest date in (arriveAlice, arriveBob) and the earliest date in (leaveAlice, leaveBob)
     * @return
     */
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res;

        vector<int> arriveAliceV = splitDate(arriveAlice);
        vector<int> leaveAliceV = splitDate(leaveAlice);
        vector<int> arriveBobV = splitDate(arriveBob);
        vector<int> leaveBobV = splitDate(leaveBob);
        
        vector<int> arrives;
        vector<int> leaves;
        
        arrives = (arriveAliceV[0] > arriveBobV[0]) ? arriveAliceV : (arriveAliceV[0] < arriveBobV[0] ? arriveBobV : (arriveAliceV[1] > arriveBobV[1] ? arriveAliceV: arriveBobV));
        leaves = (leaveAliceV[0] < leaveBobV[0]) ? leaveAliceV : (leaveAliceV[0] > leaveBobV[0] ? leaveBobV : (leaveAliceV[1] < leaveBobV[1] ? leaveAliceV: leaveBobV));

        if(leaves[0] < arrives[0]) return 0;
        if(leaves[0] == arrives[0] & leaves[1] < arrives[1]) return 0;
        
        if(arrives[0] == leaves[0]){
            res = leaves[1] - arrives[1] + 1;
        }else{
            res = days_of_month[arrives[0]] - arrives[1] + 1; //本月
            for (int i = arrives[0] + 1; i < leaves[0]; ++i) {
                res += days_of_month[i];
            }
            res += leaves[1];
        }

        return res;
    }
};

int main(){
    Solution so;
    cout<<so.countDaysTogether("03-05","07-14","04-14","09-21")<<endl;
}