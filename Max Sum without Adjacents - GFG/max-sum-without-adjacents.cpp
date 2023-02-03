//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    int dp[n][2];
	    dp[0][0] = arr[0];
	    dp[0][1] = 0;
	    
	    for(int i = 1;i < n;i++){
	        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
	        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	    }
	    
	    return max(dp[n - 1][0], dp[n - 1][1]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends