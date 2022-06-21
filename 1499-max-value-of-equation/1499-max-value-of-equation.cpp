class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        set<pair<int, int>> s;
        int n = points.size(), x = 0, y = 1;
        int ans = -1e9;

        while(x < n){
            if(y < n and k >= points[y][0] - points[x][0]){
                s.insert({points[y][0] + points[y][1], y});
                y++;
            }
            else {
                while(!s.empty() and s.rbegin()->second <= x){
                    s.erase({s.rbegin()->first, s.rbegin()->second});
                }

                if(s.size()){
                    auto u = s.rbegin();
                    int sum = points[u->second][0] - points[x][0] + points[u->second][1] + points[x][1];
                    ans = max(ans, sum);
                }
                x++;
            }
        }

        return ans;
    }
};