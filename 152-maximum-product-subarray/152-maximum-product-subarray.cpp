class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         dp
//         int mx,mn,ans;
//         int n = nums.size();
//         mx = mn = ans = nums[0];

//         for(int i = 1;i<n;i++){
//             if(nums[i]<0) swap(mx,mn);
//             mx = max(mx*nums[i],nums[i]);
//             mn = min(mn*nums[i],nums[i]);
//             ans = max(ans,mx);
//         }

//         return ans;

        int n = nums.size();
        int ans = -1e9;
        int l = 1;
        int r = 1;

        for(int i = 0;i<n;i++){
            l = l*nums[i];
            r = r*nums[n-i-1];

            ans = max({ans,l,r});

            if(l==0) l = 1;
            if(r==0) r = 1;
        }
        
        return ans;
    }
};