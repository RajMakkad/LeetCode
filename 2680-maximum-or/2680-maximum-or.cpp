class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> or_r(n);
        or_r[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            or_r[i] = (nums[i] | or_r[i + 1]);
        long long or_l = 0;
        long long sub = 0, ans = 0;
        for(int i = 0;i < n; i++){
            long long num = nums[i];
            sub = (or_l) | (num << k) | (i != n - 1 ? or_r[i + 1] : 0);
            ans = max(ans, sub);
            or_l |= nums[i];
        }
        return ans;
    }
};