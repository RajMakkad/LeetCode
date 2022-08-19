class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> have, need;
        
        for(auto i:nums) have[i]++;
        for(auto i:nums){
            if(have[i] > 0){
                if(need[i] > 0){
                    have[i]--, need[i]--;
                    need[i + 1]++;
                }
                else {
                    if(have[i + 1] > 0 and have[i + 2] > 0){
                        have[i]--, have[i + 1]--, have[i + 2]--;
                        need[i + 3]++;
                    }
                    else return false;
                }
            }
        }
        
        return true;
    }
};