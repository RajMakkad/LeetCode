class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> flip(n + 1, 0);
        for(int i = 0;i < n;i++){
            if(i > 0)
                flip[i] += flip[i - 1];
            if(((flip[i] & 1) ^ nums[i]) == 0){
                if(i > n - k)
                    return -1;
                ans++;
                flip[i]++;
                flip[i + k]--;
            }
        }
        return ans;
    }
};