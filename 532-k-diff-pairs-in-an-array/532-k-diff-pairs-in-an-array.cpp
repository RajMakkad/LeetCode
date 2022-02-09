class Solution {
public:
    int findPairs(vector<int>& nums, int k){
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            if(binary_search(nums.begin() + i + 1,nums.end(),nums[i] + k)) ans++;
        }

        return ans;
    }
};