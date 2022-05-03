bool blast(vector<int> &a,vector<int> &b){
    long double d = sqrtl((long double)(a[0] - b[0])*(a[0] - b[0]) + (long double)(a[1] - b[1])*(a[1] - b[1]));
    return a[2] >= d;
}

class Solution {
    int dfs(int node,vector<int> &blasted,vector<int> g[]){
        blasted[node] = 1;
        int count = 1;

        for(int i:g[node]){
            if(blasted[i] == 0){
                count += dfs(i,blasted,g);
            }
        }
    
        return count;
    }
public:
    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size();
        vector<int> g[n];

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                bool range = blast(b[i],b[j]);
                if(range) g[i].push_back(j);
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            vector<int> blasted(n,0);
            ans = max(ans,dfs(i,blasted,g));
        }

        return ans;
    }
};