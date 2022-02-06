class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();
        int cnt = 0;
        int ans = 0;
        int num = nums[0];

        for(int i = 0;i<n;i++){
            if(num == nums[i]){
                cnt++;
                if(cnt > 2) nums[i] = 1e6;
                else ans++;
            }
            else{
                num = nums[i];
                cnt = 1;
                ans++;
            }
        }

        int gap = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1e6) gap++;
            else swap(nums[i],nums[i - gap]);
        }

        return ans;
    }
};

