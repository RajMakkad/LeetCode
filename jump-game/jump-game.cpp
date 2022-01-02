class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n - 1;i++){
            sum = max(sum,nums[i]);
            if(sum==0) return false;
            sum--;
        }
        
        return true;
    }
};