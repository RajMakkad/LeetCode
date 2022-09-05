#define ll long long int
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        int n = nums.size();
        int ans = n;
        
        for(auto &i:nums) sum += i;
        int k = sum % p;
        
        if(k == 0) return 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            int need = (sum % p - k + p) % p;
            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }
            
            mp[sum % p] = i;
        }
        
        return ans == n ? -1: ans;
    }
};