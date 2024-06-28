class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<long long> connections(n, 0);
        for(auto &i: roads) {
            connections[i[0]]++;
            connections[i[1]]++;
        }
        sort(connections.begin(), connections.end());
        for(int i = n - 1;i >= 0; i--) 
            ans += (i + 1) * connections[i];
        return ans;
    }
};