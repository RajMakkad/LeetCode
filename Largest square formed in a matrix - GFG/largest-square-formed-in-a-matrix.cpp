// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int ans = 0;
        vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));
        
        for(int r = 1;r <= n;r++){
            for(int c = 1;c <= m;c++){
                if(mat[r - 1][c - 1] == 1){
                    int a = min({dp[r - 1][c], dp[r - 1][c - 1], dp[r][c - 1]});
                    dp[r][c] = a + 1;
                    
                    ans = max(ans, dp[r][c]);
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends