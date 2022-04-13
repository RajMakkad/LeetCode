class Solution {
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> a(n);

        for(int i = 0;i<n;i++){
            a[i].first = scores[i];
            a[i].second = ages[i];
        }

        sort(a.begin(),a.end(),comp);

        vector<int> dp(n,0);
        int ans = 0;

        for(int e = 0;e < n;e++){
            dp[e] = a[e].first;
            for(int s = 0;s < e;s++){
                if(a[e].second >= a[s].second){
                    dp[e] = max(dp[e],a[e].first + dp[s]);
                }
            }
            ans = max(ans,dp[e]);
        }
        
        return ans;
    }
};