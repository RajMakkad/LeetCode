class Solution {
public:
    int longestConsecutive(vector<int>& nums){ // unordered_map average time complexity O(1)
        int n = nums.size();
        int ans = 0;
        vector<int> vis(n,0);
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++) mp[nums[i]] = i;

        for(auto &i:nums){
            if(vis[mp[i]]) continue;
            int count = 1;

            int num = i + 1;
            while(mp.find(num) != mp.end()){
                vis[mp[num]] = 1;
                num++;
                count++;
            }

            num = i - 1;
            while(mp.find(num) != mp.end()){
                vis[mp[num]] = 1;
                num--;
                count++;
            }

            ans = max(ans,count);
        }

        return ans;
    }
};