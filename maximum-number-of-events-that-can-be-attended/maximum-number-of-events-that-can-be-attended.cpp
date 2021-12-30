class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int i = 0;
        int d = 1;
        int ans = 0;
        
        priority_queue<int,vector<int>,greater<int>> q;
        sort(events.begin(),events.end());
        
        while(q.size() || i<n){
            if(q.empty()) d = events[i][0];
            while(i<n and d>=events[i][0]) q.push(events[i++][1]);
            ans++;
            d++;
            q.pop();
            
            while(q.size() and d>q.top()) q.pop();
        }
        
        return ans;
    }
};