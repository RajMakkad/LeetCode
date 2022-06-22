// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

#define mod 1000000007
class Solution{
  public:
    int fun(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1,vector<int>(3, 0));

        for(int i = 1;i <= n;i++){
            int x = s[i - 1] - 'a';
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];

            if(x == 0) dp[i][x] = (dp[i][x] + dp[i - 1][x] + 1)%mod;
            else dp[i][x] = (dp[i][x] + (dp[i - 1][x] + dp[i - 1][x - 1])%mod)%mod;
        }

        return dp[n][2];
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends