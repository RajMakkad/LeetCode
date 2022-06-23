class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> ans = {1, nums[0]};
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == ans.second) ans.first++;
            else {
                ans.first--;
                if(ans.first < 0){
                    ans = {1, nums[i]};
                }
            }
        }
        
        return ans.second;
    }
};