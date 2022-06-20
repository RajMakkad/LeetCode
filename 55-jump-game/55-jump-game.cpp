class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0;i < nums.size(); i++){
            if(maxReach >= i) maxReach = max(maxReach, i + nums[i]);
            else return false;
        }
        
        return true;
    }
};