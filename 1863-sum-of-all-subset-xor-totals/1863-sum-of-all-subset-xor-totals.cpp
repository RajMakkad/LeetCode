class Solution {
    void helper(int idx, int &n, int sum, int &ans, vector<int> &nums){
        if(idx >= n) 
            ans += sum;
        else {
            idx++;
            helper(idx, n, sum ^ nums[idx - 1], ans, nums);
            helper(idx, n, sum, ans, nums);
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), ans = 0, idx = 0, sum = 0;
        helper(idx, n, sum, ans, nums);
        return ans;
    }
};