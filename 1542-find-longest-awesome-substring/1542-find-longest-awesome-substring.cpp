class Solution {
public:
    int longestAwesome(string s) {
        vector<int> mp(1024,-2);
        int sum = 0;
        int ans = 0;
        mp[sum] = -1;

        for(int i = 0;i<s.length();i++){
            int num = s[i] - '0';
            sum ^= (1<<num);
            if(mp[sum] != -2){
                ans = max(ans,i - mp[sum]);
            }
            else mp[sum] = i;

            for(int p = 0;p<=9;p++){
                if(mp[(sum ^ (1<<p))] != -2){
                    ans = max(ans,i - mp[(sum ^ (1<<p))]);
                }
            }
        }

        return ans;
    }
};