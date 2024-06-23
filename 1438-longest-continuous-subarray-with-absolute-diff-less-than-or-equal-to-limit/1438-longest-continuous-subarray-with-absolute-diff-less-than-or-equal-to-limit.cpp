class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        set<pair<int, int>> s;
        int i = 0, j = 0, ans = 0, n = nums.size();
        while(j < n){
            s.insert({nums[j], j++});
            auto min_ = *s.begin();
            auto max_ = *s.rbegin();
            while(max_.first - min_.first > limit){
                s.erase({nums[i], i++});
                min_ = *s.begin();
                max_ = *s.rbegin();
            }
            ans = max(ans, (int)s.size());
        }
        return ans;
    }
};