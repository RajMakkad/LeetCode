class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count[100 + 1] = {0};
        int ans = 0;
        for(int i = 0;i < n;i++){
            count[nums[i]]++;
            ans += count[nums[i]] - 1;
        }

        return ans;
    }
};