class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n = a.size();
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i = n - 1;i>=0;i--){
            mp[a[i]] = 1 + mp[a[i] + d];
            ans = max(ans,mp[a[i]]);
        }

        return ans;
    }
};