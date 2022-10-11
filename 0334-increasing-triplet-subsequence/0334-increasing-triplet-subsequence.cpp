class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX;
        int s = INT_MAX;

        for(auto i:nums){
            if(f >= i) f = i;
            else if(s >= i) s = i;
            else return true;
        }
        
        return false;
    }
};