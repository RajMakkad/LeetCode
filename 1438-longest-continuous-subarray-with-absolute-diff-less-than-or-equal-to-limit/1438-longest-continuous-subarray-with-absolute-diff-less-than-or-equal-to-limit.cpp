class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int left = 0, ans = 0;
        for(auto &i: nums){
            m.insert(i);
            while(*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[left++]));
            ans = max(ans, (int)m.size());
        }
        return ans;
    }
};