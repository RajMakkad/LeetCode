class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        multiset<int> s1,s2;

        s1.insert(nums[0]);
        for(int i = 1;i<n;i++) s2.insert(nums[i]);

        for(int i = 1;i<n - 1;i++){
            auto b = s1.begin();
            s2.erase(s2.find(nums[i]));
            auto u = s2.upper_bound(*b);
            if(u != s2.end() and nums[i] > *u) return true;
            s1.insert(nums[i]);
        }

        return false;
    }
};