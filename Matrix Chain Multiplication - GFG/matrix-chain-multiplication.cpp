// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int memoize(int s,int e,int arr[],vector<vector<int>> &dp){
        if(s > e) return 0;
        if(dp[s][e] != 0) return dp[s][e];

        int optimal = 1e9;

        for(int i = s;i<=e;i++){
            int sub = memoize(s,i - 1,arr,dp) + arr[s - 1]*arr[i]*arr[e + 1] + memoize(i + 1,e,arr,dp);
            optimal = min(optimal,sub);
        }

        return dp[s][e] = optimal;
    }
public:
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n,vector<int>(n,0));
        memoize(1,n - 2,arr,dp);

        return dp[1][n - 2];
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends