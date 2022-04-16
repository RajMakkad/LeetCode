// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    int memoization(int x,int k,vector<int> &dp,vector<int> &nums){
        int n = nums.size();
        if(x >= n) return 0;
        if(dp[x] != -1) return dp[x];

        int optimal = 1e9;
        int sum = 0;

        for(int i = x;i<n;i++){
            sum += nums[i];
            if(k >= sum + (i - x)){
                int cost = 0;
                if(i != n - 1) cost = (k - sum - (i - x))*(k - sum - (i - x));
                optimal = min(optimal,cost + memoization(i + 1,k,dp,nums));
            }
        }

        return dp[x] = optimal;
    }
public:
    int solveWordWrap(vector<int>nums, int k){ 
        int n = nums.size();
        vector<int> dp(n + 1,-1);

        return memoization(0,k,dp,nums);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends