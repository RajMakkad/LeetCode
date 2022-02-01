// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
   vector <int> dijkstra(int N, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>> pq;
        pq.push({0, S});
        vector<int> dist(N+1, INT_MAX);
        dist[S] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            d*=(-1);
            pq.pop();
            for(auto v: adj[node]){
                int child = v[0], w = v[1];
                if(dist[child] > (d+w)){
                    dist[child] = (d+w);
                    pq.push({-1*(d+w), child});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends