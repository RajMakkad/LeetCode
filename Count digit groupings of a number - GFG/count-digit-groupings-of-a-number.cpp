// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int memoization(int x, int sum, vector<vector<int>> &dp, string &s){
        int n = s.length();
        if(x == n) return 1;
        if(dp[x][sum] != -1) return dp[x][sum];

        dp[x][sum] = 0;
        int currSum = 0;

        for(int i = x;i<n;i++){
            currSum += (s[i] - '0');
            if(currSum >= sum){
                dp[x][sum] += memoization(i + 1, currSum, dp, s);
            }
        }

        return dp[x][sum];
    }
	public:
	int TotalCount(string s){
	    int n = s.length();
        vector<vector<int>> dp(n + 1,vector<int>(1000, -1));
        return memoization(0, 0, dp, s);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends