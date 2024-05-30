class Solution {
public:
    int countTriplets(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int a = 0, b = 0;
                for(int f = i; f < j; f++)
                    a ^= nums[f];
                for(int k = j; k < n; k++){
                    b ^= nums[k];
                    ans += a == b ? 1 : 0;
                }
            }
        }
        return ans;
    }
};