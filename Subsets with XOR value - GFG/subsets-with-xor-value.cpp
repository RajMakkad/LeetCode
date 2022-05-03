// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    int memoization(int n,int k,vector<int> &a,vector<vector<int>> &dp){
        if(n == 0){
            return k == 0;
        }
        if(dp[n][k] != -1) return dp[n][k];

        dp[n][k] = memoization(n - 1,(k ^ a[n - 1]),a,dp);
        dp[n][k] += memoization(n - 1,k,a,dp);

        return dp[n][k];
    }
public:
    int subsetXOR(vector<int> a, int n, int k) {
        vector<vector<int>> dp(n + 1,vector<int>(1000,-1));
        return memoization(n,k,a,dp);
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends