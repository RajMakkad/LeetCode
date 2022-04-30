#define pi pair<string,double>
class Solution {
    map<string,vector<pi>> mp;
    double dfs(string start,string end,map<string,int> &visited){
        visited[start] = 1;
        if(start == end) return 1.0;
        for(auto i:mp[start]){
            if(visited[i.first] == 1) continue;
            
            double temp = dfs(i.first,end,visited);
            if(temp > 0.0){
                return temp*i.second;
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& value, vector<vector<string>>& queries){
        int n = e.size();
        map<string,int> present;
        for(int i = 0;i<n;i++){
            double x = 1.0/value[i];
            mp[e[i][0]].push_back({e[i][1],value[i]});
            mp[e[i][1]].push_back({e[i][0],x});
            present[e[i][0]] = present[e[i][1]] = 1;
        }

        int m = queries.size();
        vector<double> ans(m);
        for(int i = 0;i<m;i++){
            double x = -1.0;
            map<string,int> visited;
            if(present[queries[i][0]]) x = dfs(queries[i][0],queries[i][1],visited);
            ans[i] = x;
        }

        return ans;
    }
};