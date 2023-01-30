//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class Solution{
    int memoization(int node, int parent, int light, vector<int> g[], vector<vector<int>> &dp){
        if(dp[node][light] != -1)
            return dp[node][light];
            
        int count = light;
        for(auto &i: g[node]){
            if(i == parent)
                continue;
            
            int sub = memoization(i, node, light ^ 1, g, dp);
            if(light == 1)
                sub = min(sub, memoization(i, node, 1, g, dp));
            
            count += sub;
        }
        
        return dp[node][light] = count;
    }
  public:
    int countVertex(int n, vector<vector<int>>edges){
        vector<int> g[n + 1];
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        
        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
        int ans = min(memoization(1, 1, 0, g, dp), memoization(1, 1, 1, g, dp));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends