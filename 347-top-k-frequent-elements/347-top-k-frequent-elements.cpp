#define pi pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;

        priority_queue<pi,vector<pi>,greater<pi>> q;
        for(auto i:mp){
            q.push({i.second,i.first});
            if(q.size() > k) q.pop();
        }

        vector<int> ans;
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};