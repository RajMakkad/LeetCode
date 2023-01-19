class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        map<int, int> mp;
        
        mp[0]++;
        
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            sum %= k;
            sum += k;
            sum %= k;
            
            ans += mp[sum];
            mp[sum]++;
        }
        
        return ans;
    }
};