class Solution {
    void dfs(int node, vector<bool> &reach, vector<vector<int>>& rooms){
        reach[node] = true;
        for(auto i:rooms[node]){
            if(!reach[i])
                dfs(i, reach, rooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> reach(n, false);
        
        dfs(0, reach, rooms);
        
        for(int i = 0;i < n;i++){
            if(!reach[i])
                return false;
        }
        
        return true;
    }
};