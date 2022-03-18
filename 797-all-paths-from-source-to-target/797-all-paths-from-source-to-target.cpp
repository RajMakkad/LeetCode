class Solution {
public:
    void paths(vector<vector<int>> &ans,vector<int> &sub,vector<int> adj[],int node,int &target){
        
        if(node == target){
            ans.push_back(sub);
            return ;
        }

        for(auto i:adj[node]){
            sub.push_back(i);
            paths(ans,sub,adj,i,target);
            sub.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> adj[n];

        for(int i = 0;i<n;i++){
            for(int it = 0;it<graph[i].size();it++){
                adj[i].push_back(graph[i][it]);
            }
        }

        vector<vector<int>> ans;
        vector<int> sub;
        
        sub.push_back(0);
        int target = n - 1;

        paths(ans,sub,adj,0,target);

        return ans;
    }
};