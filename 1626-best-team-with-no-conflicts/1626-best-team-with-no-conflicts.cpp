class Solution {
    static bool comp(const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> v(n, vector<int>(2));
        
        for(int i = 0;i < n;i++){
            v[i][0] = scores[i];
            v[i][1] = ages[i];
        }
        
        sort(v.begin(), v.end(), comp);
        vector<int> dp(n, 0);
        
        int ans = 0;
        
        for(int e = 0;e < n;e++){
            dp[e] = v[e][0];
            for(int s = 0;s < e;s++){
                if(v[e][0] >= v[s][0])
                    dp[e] = max(dp[e], dp[s] + v[e][0]);
            }
            
            ans = max(ans, dp[e]);
        }
        
        return ans;
    }
};