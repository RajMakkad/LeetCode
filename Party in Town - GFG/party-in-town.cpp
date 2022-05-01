// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dmax = 0;
    void dfs(int node,int parent,int d,vector<vector<int>> &adj){
        dmax = max(dmax,d);
        for(auto i:adj[node]){
            if(i == parent) continue;
            dfs(i,node,d + 1,adj);
        }
    }
public:
    int partyHouse(int n, vector<vector<int>> &adj){
        int ans = n;
        for(int i = 1;i<=n;i++){
            dmax = 0;
            dfs(i,-1,0,adj);
            ans = min(ans,dmax);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends