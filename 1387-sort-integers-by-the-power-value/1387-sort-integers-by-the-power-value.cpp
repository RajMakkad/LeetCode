class Solution {
    int memoization(int x, vector<int> &dp){
        if(x == 1) return 0;
        if(dp[x] != -1) return dp[x];

        if(x % 2) return dp[x] = memoization(3*x + 1, dp) + 1;
        return dp[x] = memoization(x/2, dp) + 1;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1000000, -1);
        vector<pair<int, int>> a;

        for(int i = lo; i <= hi; i++){
            int p = memoization(i, dp);
            a.push_back({p, i});
        }

        sort(a.begin(), a.end());
        return a[k - 1].second;
    }
};