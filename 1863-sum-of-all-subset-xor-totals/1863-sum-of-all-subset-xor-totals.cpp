class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, range = 1 << nums.size();
        for(int i = 1; i < range; i++){
            int subset = 0;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j))
                    subset ^= nums[j];
            }
            ans += subset;
        }
        return ans;
    }
};