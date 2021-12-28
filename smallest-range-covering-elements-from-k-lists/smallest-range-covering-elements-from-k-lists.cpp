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
        multiset<int> st;
        int n = sub.size();

        for(int i = 0;i<n;i++){
            int num = sub[i].first;
            int ind = sub[i].second;

            if(mp.find(ind) != mp.end()) st.erase(st.find(mp[ind]));
            mp[ind] = num;
            st.insert(num);

            if(st.size() == k){
                auto end = st.end();
                auto start = st.begin();
                end--;

                int diff = *end - *start;

                if(ans.first > diff){
                    ans.first = diff;
                    ans.second = {*start,*end};
                }
            }
        }
        return ans.second;
    }
};