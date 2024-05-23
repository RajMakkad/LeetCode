class Solution {
    void solve(int idx, int &k, int &ans, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(idx >= n) {
            ans++;
        } else {
            int element = nums[idx] - k;
            if(element < 0 || dp[element] == 0) {
                dp[nums[idx]]++;
                solve(idx + 1, k, ans, nums, dp);
                dp[nums[idx]]--;
            }
            solve(idx + 1, k, ans, nums, dp);
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1000 + 1, 0);
        int ans = -1;
        solve(0, k, ans, nums, dp);
        return ans;
    }
};