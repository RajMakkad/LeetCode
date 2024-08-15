class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change = {0, 0};
        for(auto &i: bills){
            if(i == 5)
                change[0]++;
            else if(i == 10){
                if(change[0] == 0)
                    return false;
                change[0]--;
                change[1]++;
            }
            else {
                if(change[0] > 0 and change[1] > 0){
                    change[0]--;
                    change[1]--;
                }
                else if(change[0] >= 3){
                    change[0] -= 3;
                }
                else 
                    return false;
            }
        }
        return true;
    }
};