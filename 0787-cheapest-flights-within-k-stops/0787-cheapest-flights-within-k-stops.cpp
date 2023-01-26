#define pi pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pi> g[n];
        
        for(auto &i: flights){
            g[i[0]].push_back({i[1], i[2]});
        }
        
        queue<pi> q;
        vector<int> price(n, 1e9);
        
        price[src] = 0;
        q.push({0, src});
        
        while(k >= 0 and !q.empty()){
            k--;
            int size = q.size();
            while(size--){
                auto x = q.front();
                q.pop();
                
                for(auto &i: g[x.ss]){
                    if(price[i.ff] > x.ff + i.ss){
                        price[i.ff] = x.ff + i.ss;
                        q.push({price[i.ff], i.ff});
                    }
                }
            }
        }
        
        return price[dst] == 1e9 ? -1: price[dst];
    }
};