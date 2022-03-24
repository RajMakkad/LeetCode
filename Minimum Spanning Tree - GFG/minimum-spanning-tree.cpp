// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define pi pair<int,int>
class Solution{
	public:
    int spanningTree(int n, vector<vector<int>> g[]){

        vector<int> p(n,-1), key(n,1e9), inMst(n,0);
        priority_queue<pi,vector<pi>,greater<pi>> q;

        key[0] = 0;

        q.push({0,0});

        while(!q.empty()){
            int node = q.top().second;
            inMst[node] = 1;
            q.pop();

            for(auto &i:g[node]){
                if(inMst[i[0]] == 0 and key[i[0]] > i[1]){
                    key[i[0]] = i[1];
                    p[i[0]] = node;
                    q.push({i[1],i[0]});
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += key[i];
        }

        return ans;
    }
};
// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends