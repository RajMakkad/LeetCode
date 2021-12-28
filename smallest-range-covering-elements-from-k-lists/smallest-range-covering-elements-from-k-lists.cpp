class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int,int>> sub;

        for(int i = 0;i<k;i++){
            for(auto s:nums[i]){
                sub.push_back({s,i});
            }
        }

        sort(sub.begin(),sub.end());
        pair<int,vector<int>> ans = {1e9,{}};
        map<int,int> mp;
        int n = sub.size();
        int s = 0;

        for(int i = 0;i<n;i++){
            int num = sub[i].first;
            int end = sub[i].second;

            mp[end]++;
            while(mp.size() == k){
                if(ans.first > num - sub[s].first){
                    ans.first = num - sub[s].first;
                    ans.second = {sub[s].first,num};
                }

                int start = sub[s].second;
                mp[start]--;
                if(mp[start] == 0) mp.erase(start);
                s++;
            }
        }
        return ans.second;
    }
};