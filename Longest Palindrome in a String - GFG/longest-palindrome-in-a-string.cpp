// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        int n = str.length();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0));

        vector<int> ans = {0, 0};

        for(int g = 0; g < n; g++){
            for(int s = 0;s + g < n;s++){
                int e = s + g;
                if(g == 0) dp[s][e] = 1;
                else if(g == 1 and str[s] == str[e]) dp[s][e] = 1;
                else if(dp[s + 1][e - 1] and str[s] == str[e]) dp[s][e] = 1;

                if(dp[s][e] and (e - s + 1) > ans[1]){
                    ans = {s, e - s + 1};
                }
            }
        }

        return str.substr(ans[0], ans[1]);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends