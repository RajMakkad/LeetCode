class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads){
        map<pair<int,int>,int> mp;
        vector<int> degree(n,0);

        for(auto &i:roads){
            mp[{i[0],i[1]}]++;
            mp[{i[1],i[0]}]++;
            degree[i[0]]++;
            degree[i[1]]++;
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                int sum = degree[i] + degree[j] - mp[{i,j}];
                ans = max(ans,sum);
            }
        }

        return ans;
    }
};