// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 class Solution {
	public:
		int CountWays(string str){
            int n = str.length();
            int mod = 1000000007;
		    int dp[n + 1] = {0};

            dp[0] = 1;

            for(int i = 1;i<=n;i++){
                if(str[i - 1] != '0') dp[i] = dp[i - 1]%mod;
                if(i>1 and str[i - 2] != '0'){
                    int num = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
                    if(num>=1 and num<=26) dp[i] = (dp[i] + dp[i - 2]%mod)%mod;
                }
            }

            return dp[n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends