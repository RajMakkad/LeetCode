class Solution {
    void workingHour(int node,int &ans,int time,vector<int> g[],vector<int> &informTime){
        ans = max(ans,time);
        
        for(auto &i:g[node]){
            workingHour(i,ans,time + informTime[node],g,informTime);
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        vector<int> g[n];

        for(int i = 0;i<n;i++){
            if(i != headID){
                g[manager[i]].push_back(i);
            }
        }

        int ans = 0;
        workingHour(headID,ans,0,g,informTime);

        return ans;
    }
};