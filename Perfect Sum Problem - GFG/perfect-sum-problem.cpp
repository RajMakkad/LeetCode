// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
   
#define mod 1000000007
class Solution{
    int memoization(int n, int sum, vector<vector<int>> &dp, int arr[], int &size){
        if(n == 0 and sum == 0) return 1;
        if(n == 0) return 0;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        int ways = 0;
        if(sum >= arr[n - 1]) ways = (ways + memoization(n - 1, sum - arr[n - 1], dp, arr, size))%mod;
        ways = (ways + memoization(n - 1, sum, dp, arr, size))%mod;
        
        return dp[n][sum] = ways;
    }
	public:
	int perfectSum(int arr[], int n, int sum){
	    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
	    return memoization(n, sum, dp, arr, n);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends