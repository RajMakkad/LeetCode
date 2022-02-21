// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n){
        vector<vector<int>> dp(n,vector<int>(n,0));
    
        for(int g = 0;g<n;g++){
            for(int s = 0;s + g < n;s++){
                int e = s + g;
                if(g == 0) dp[s][e] = freq[s];
                else if(g == 1) dp[s][e] = min(freq[s] + freq[e]*2,freq[s]*2 + freq[e]);
                else{
                    int sum = 0;
                    dp[s][e] = 1e9;
                    for(int i = s;i<=e;i++) sum += freq[i];
                    for(int i = s;i<=e;i++){
                        int l = 0;
                        int r = 0;
    
                        if(i != 0) l = dp[s][i - 1];
                        if(i != n - 1) r = dp[i + 1][e];
                        dp[s][e] = min(dp[s][e],l + r);
                    }
    
                    dp[s][e] += sum;
                }
            }
        }
    
        return dp[0][n - 1];
    
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends