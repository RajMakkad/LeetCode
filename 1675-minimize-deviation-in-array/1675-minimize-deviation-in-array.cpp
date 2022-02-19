class Solution{
public:
    int minimumDeviation(vector<int>& nums){
        set<pair<int,int>> s;
        int n = nums.size();
        int x = 0;
    
        for(auto &i:nums){
            x = i;
            while(x % 2 == 0) x /= 2;
            s.insert({x,i});
        }

        int cnt = n*(log2(n) + 1) + 2*n;
        int ans = 1e9;

        while(cnt--){
            auto u = s.begin();
            auto v = s.end(); v--;
            ans = min(ans,v->first - u->first);
            if(u->first == v->first) break;
            pair<int,int> p;

            if(u->first < u->second || u->first%2){
                p = {u->first,u->second};
                s.erase(u);
                s.insert({2*p.first,p.second});
            }
            else if(v->first%2 == 0){
                p = {v->first/2,v->second};
                s.erase(v);
                s.insert({p.first,p.second});
            }
            else break;
        }

        return ans;
    }
};
