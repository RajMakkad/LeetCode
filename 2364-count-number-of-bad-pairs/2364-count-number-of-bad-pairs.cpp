class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long ans = 0, n = nums.size();
        
        for(int i = 0;i < n;i++){
            int p = nums[i] - i;
            mp[p]++;
        }
        
        for(auto &i:mp){
            ans += (n - i.second) * i.second;
        }
        
        return ans/2;
    }
};