class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days){
        int n = apples.size();
        int ans = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i = 0;i<n;i++){
            if(apples[i]) q.push({i + days[i],apples[i]});
            if(q.size()){
                auto u = q.top(); q.pop();
                ans++;
                u.second--;
                if(u.second) q.push({u.first,u.second});
            }

            while(q.size() and i + 1 >= q.top().first) q.pop();
        }

        int d = n;
        while(q.size()){
            auto u = q.top(); q.pop();
            ans++;
            u.second--;
            if(u.second) q.push({u.first,u.second});
            d++;
            while(q.size() and d >= q.top().first) q.pop();
        }

        return ans;
    }
};