class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int frq[100 + 1] = {0};
        int maxFrq = 0;
        for(int i = 0; i < n;i++){
            frq[nums[i]]++;
            maxFrq = max(maxFrq, frq[nums[i]]);
        }
        
        int ans = 0;
        for(int i = 0;i <= 100;i++){
            if(frq[i] == maxFrq)
                ans += maxFrq;
        }
        
        return ans;
    }
};