// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool detectCycle(int node,vector<int> &vis,vector<int> &inStack,vector<int> g[]){
        vis[node] = inStack[node] = 1;
        for(auto &i:g[node]){
            if(vis[i] == 0){
                if(detectCycle(i,vis,inStack,g)) return true;
            }
            else if(inStack[i] != 0) return true;
        }
    
        inStack[node] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> g[]){
        vector<int> vis(n,0),inStack(n,0);
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                if(detectCycle(i,vis,inStack,g)) return true;
            }
        }

    return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends