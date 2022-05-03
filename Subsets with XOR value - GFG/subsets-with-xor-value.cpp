// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// class Solution{
// public:
//     int subsetXOR(vector<int> a, int n, int k) {
//         vector<vector<int>> dp(n + 1,vector<int>(128,0));

//         dp[0][0] = 1;
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<=k;j++){
//                 dp[i + 1][j] += dp[i][j];
//                 dp[i + 1][(a[i] ^ j)] += dp[i][j];
//             }
//         }

//         return dp[n][k];
//     }
// };
class Solution{
public:
    int helper(vector<int>arr,vector<vector<int>>&dp,int K,int i)
    {
        if(i==arr.size())
            return K==0;
        if(dp[i][K]!=-1)
            return dp[i][K];
        
        else
        {
            int op1=helper(arr,dp,K,i+1);
            int op2=helper(arr,dp,K^arr[i],i+1);
            return dp[i][K]=op1+op2;
        }
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>>dp(N,vector<int>(1000,-1));
        
        return helper(arr,dp,K,0);
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