// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int solve(int n, int m, vector<vector<int>> &dp, string &p, string &s){
        if(n == 0 and m == 0) return dp[n][m] = 1;
        if(n == 0) return dp[n][m] = 0;
        if(m == 0){
            if(p[n - 1] == '*') return dp[n][m] = solve(n - 1, m, dp, p, s);
            return dp[n][m] = 0;
        }
        
        if(dp[n][m] != -1) return dp[n][m];
        dp[n][m] = 0;
        
        if(p[n - 1] == s[m - 1] || p[n - 1] == '?')
            dp[n][m] = solve(n - 1, m - 1, dp, p, s);
        
        if(p[n - 1] == '*')
            dp[n][m] = solve(n - 1, m, dp, p, s) | solve(n, m - 1, dp, p, s);
            
        return dp[n][m];
    }
  public:
    int wildCard(string p, string s){
        int n = p.length(), m = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return solve(n, m, dp, p, s);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends