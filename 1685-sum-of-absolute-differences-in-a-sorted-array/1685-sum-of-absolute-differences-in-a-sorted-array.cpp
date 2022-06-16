class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n + 1, 0);
        p[0] = nums[0];

        for(int i = 1;i<n;i++){
            p[i] = p[i - 1] + nums[i];
        }

        for(int i = 0;i<n;i++){
            int sum = 0;
            if(i + 1 < n){
                sum = p[n - 1] - p[i] - (n - i - 1) * nums[i];
            }

            if(i > 0){
                sum += (i * nums[i] - p[i - 1]);
            }

            nums[i] = sum;
        }
        
        return nums;
    }
};