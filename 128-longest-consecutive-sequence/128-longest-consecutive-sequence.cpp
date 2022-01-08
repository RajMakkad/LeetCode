class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto &i:nums) mp[i] = 1;

        for(auto &i:mp){
            mp[i.first] = mp[i.first - 1] + 1;
            ans = max(ans,mp[i.first]);
        }

        return ans;
    }
};