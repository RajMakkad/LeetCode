class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while(e > s){
            int sum = nums[s] + nums[e];
            if(sum == target) break;
            else if(sum > target) e--;
            else s++;
        }
        
        return {s + 1, e + 1};
    }
};