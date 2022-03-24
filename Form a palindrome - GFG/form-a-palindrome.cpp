// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    int memoization(int x,int y,vector<vector<int>> &dp,string &s){
        if(x >= y) return 0;
        if(dp[x][y] != -1) return dp[x][y];

        if(s[x] == s[y]) return dp[x][y] = memoization(x + 1,y - 1,dp,s);
        return dp[x][y] = min(memoization(x + 1,y,dp,s),memoization(x,y - 1,dp,s)) + 1;
    }
public:
    int findMinInsertions(string s){
        int n = s.length();
        int x = 0;
        int y = n - 1;

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return memoization(x,y,dp,s);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends