// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    int dp[200001];
    int memoization(int x,int k,int m,vector<int> &a){
        int n = a.size();
        if(x >= n) return true;
        if(dp[x] != -1) return dp[x];

        for(int i = x + k - 1;i<n;i++){
            if(a[i] > a[x] + m) break;
            if(memoization(i + 1,k,m,a)) return dp[x] = 1;
        }

        return dp[x] = 0;
    }
    public:
    bool partitionArray(int n, int k, int m, vector<int> &a){
        sort(a.begin(),a.end());
        memset(dp,-1,sizeof(dp));

        return memoization(0,k,m,a);
    }
}; 

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends