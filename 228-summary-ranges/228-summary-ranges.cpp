class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums){
        if(nums.empty()) return {};
        
        map<int,int> mp;
        int n = nums.size();
        int s = nums[0];
        long long c = 1;

        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i - 1] + 1) c++;
            else{
                mp[s] = c;
                s = nums[i];
                c = 1;
            }
        }
        mp[s] = c;

        vector<string> ans;
        for(auto &i:mp){
            string sub = "";
            sub += to_string(i.first);
            if(i.second != 1LL){
                sub += "->";
                i.second--;
                sub += to_string(i.first + i.second);
            }
            ans.push_back(sub);
        }

        return ans;
    }
};