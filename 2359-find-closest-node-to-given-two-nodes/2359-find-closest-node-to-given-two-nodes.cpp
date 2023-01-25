
class Solution {
    void solve(int node, vector<int> &edges, vector<int> &dist){
        queue<int> q;
        q.push(node);
        
        dist[node] = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            if(edges[x] != -1 and dist[edges[x]] > dist[x] + 1){
                dist[edges[x]] = dist[x] + 1;
                q.push(edges[x]);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, 1e9);
        vector<int> dist2(n, 1e9);
        
        solve(node1, edges, dist1);
        solve(node2, edges, dist2);
        
        int ans = 1e9;
        for(int i = 0;i < n;i++){
            ans = min(ans, max(dist1[i], dist2[i]));
        }
        
        if(ans == 1e9)
            return -1;
        
        for(int i = 0;i < n;i++){
            if(ans == max(dist1[i], dist2[i])){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};