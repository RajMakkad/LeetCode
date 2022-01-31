class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int cur = 0;
        int n = accounts.size();
        
        for(int i = 0;i<n;i++){
            for(auto a:accounts[i]) cur += a;
            ans = max(ans,cur);
            cur = 0;
        }
        
        return ans;
    }
};