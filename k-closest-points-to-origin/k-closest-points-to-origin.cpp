class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q;
        for(int i = 0;i<points.size();i++){
            int sum = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            q.push({sum,i});
            if(q.size()>k) q.pop();
        }

        vector<vector<int>> ans;
        while(q.size()){
            int in = q.top().second;
            q.pop();
            ans.push_back({points[in][0],points[in][1]});
        }
        return ans;
    }
};