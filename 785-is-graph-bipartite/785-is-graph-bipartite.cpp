class Solution{
public:
    bool dfsBipartite(int node,int c,vector<vector<int>> graph,vector<int>& colour){
        colour[node] = c;
        for(auto i:graph[node]){
            if(colour[i] == -1){
                if(!dfsBipartite(i,c^1,graph,colour)) return false;
            }
            else if(c == colour[i]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> colour(graph.size(),-1);
        
        for(int i = 0;i<graph.size();i++){
            if(colour[i]==-1){
                if(!dfsBipartite(i,1,graph,colour)) return false;
            }
        }
        
        return true;
    }
};