class Solution{
    int memoize(int index,int &d,vector<int>& a,vector<int> &dp){
        int n = a.size();
        if(index >= n) return 0;
        if(dp[index] != 0) return dp[index];

        int optimal = 0;

        for(int i = index + 1;i <= min(index + d,n - 1);i++){
            if(a[index] > a[i]) optimal = max(optimal,memoize(i,d,a,dp));
            else break;
        }

        for(int i = index - 1;i >= max(index - d,0);i--){
            if(a[index] > a[i]) optimal = max(optimal,memoize(i,d,a,dp));
            else break;
        }

        return dp[index] = optimal + 1;
    }
public:
    int maxJumps(vector<int>& a, int d) {
        int n = a.size();
        int ans = 0;
        vector<int> dp(n,0);

        for(int i = 0;i<n;i++){
            ans = max(ans,memoize(i,d,a,dp));
        }

        return ans;
    }
};