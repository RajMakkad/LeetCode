class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0;i<=n;i++){
            auto u = lower_bound(nums.begin(),nums.end(),i) - nums.begin();
            if(n - u == i) return i;
        }

        return -1;
    }
};