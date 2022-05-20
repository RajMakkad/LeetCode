class Solution {
    int upper_bound(vector<vector<int>>& events, int x){
        int s = 0;
        int e = events.size() - 1;
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            if(events[m][0] > x) e = m - 1;
            else s = m + 1;
        }

        return s;
    }
    long long memoization(int x,int k,vector<vector<int>> &dp,vector<vector<int>> &events){
        int n = events.size();
        if(x == n || k == 0) return 0;

        if(dp[x][k] != -1) return dp[x][k];

        int u = upper_bound(events,events[x][1]);

        long long ans1 = events[x][2] + memoization(u,k - 1,dp,events); // attend
        long long ans2 = memoization(x + 1,k,dp,events); // dosen't attend

        return dp[x][k] = max(ans1,ans2);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n + 1,vector<int>(k + 1,-1));

        return memoization(0,k,dp,events);
    }
};