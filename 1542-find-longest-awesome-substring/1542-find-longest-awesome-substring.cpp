class Solution {
public:
    int longestAwesome(string s) {
        map<int,int> mp;
        int sum = 0;
        int ans = 0;
        mp[sum] = -1;

        for(int i = 0;i<s.length();i++){
            int num = s[i] - '0';
            sum ^= (1<<num);
            if(mp.find(sum) != mp.end()){
                ans = max(ans,i - mp[sum]);
            }
            else mp[sum] = i;

            for(int p = 0;p<=9;p++){
                if(mp.find((sum ^ (1<<p))) != mp.end()){
                    ans = max(ans,i - mp[(sum ^ (1<<p))]);
                }
            }
        }

        return ans;
    }
};