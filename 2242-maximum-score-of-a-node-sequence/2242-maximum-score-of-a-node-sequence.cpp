class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[0] > b[0];
    }
public:
    int maximumScore(vector<int>& s, vector<vector<int>>& e){
        int n = s.size();
        vector<vector<int>> g[n];

        for(auto i:e){
            g[i[0]].push_back({s[i[1]],i[1]});
            g[i[1]].push_back({s[i[0]],i[0]});
        }

        for(int i = 0;i<n;i++){
            sort(g[i].begin(),g[i].end(),comp);
        }

        int ans = 0;
        for(auto i:e){
            int sum = s[i[0]] + s[i[1]];
            vector<vector<int>> a_1, a_2;

            for(auto p:g[i[0]]){
                if(p[1] != i[1]) a_1.push_back({p[0],p[1]});
                if(a_1.size() > 1) break;
            }

            for(auto p:g[i[1]]){
                if(p[1] != i[0]) a_2.push_back({p[0],p[1]});
                if(a_2.size() > 1) break;
            }

            for(int x = 0;x<a_1.size();x++){
                for(int y = 0;y<a_2.size();y++){
                    if(a_1[x][1] != a_2[y][1]) ans = max(ans,sum + a_1[x][0] + a_2[y][0]);
                }
            }
        }
        return ans > 0 ? ans : -1;
    }
};