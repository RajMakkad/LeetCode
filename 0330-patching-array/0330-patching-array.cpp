class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, idx = 0, m = nums.size();
        long long access = 0;
        while(access < n){
            if(idx < m and access + 1 >= nums[idx]) access += nums[idx++];
            else {
                access = access + access + 1;
                ans++;
            }
        }
        return ans;
    }
};