class Solution {
    void solve(int idx, vector<int> subset, vector<int> &nums, vector<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.push_back(subset);
        } else {
            subset.push_back(nums[idx]);
            solve(idx + 1, subset, nums, ans);
            subset.pop_back();
            solve(idx + 1, subset, nums, ans);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0, subset, nums, ans);
        return ans;
    }
};