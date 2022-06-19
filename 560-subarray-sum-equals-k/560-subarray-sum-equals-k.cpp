class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int need = sum - k;
            
            ans += mp[need];
            mp[sum]++;
        }
        
        return ans;
    }
};