#define mod 1000000007

int memoization(int x,string &s,vector<int> &dp){
    int n = s.length();
    if(x == n) return 1;
    if(dp[x] != -1) return dp[x];
    
    char c = s[x];
    int ans = 0;
    for(int i = x;i<=min(n - 1,x + 3);i++){
        if(c != s[i]) break;
        if(i == x + 3 and !(c =='7' || c == '9')) break;
        
        ans = (ans + memoization(i + 1,s,dp)%mod)%mod;
    }
    
    return dp[x] = ans;
}

class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n + 1,-1);
        
        return memoization(0,pressedKeys,dp);
    }
};