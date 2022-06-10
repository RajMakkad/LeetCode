class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int x = 0;
        int ans = 0;
        map<char,int> mp;

        for(int i = 0;i<s.length();i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[x++]]--;
            }

            ans = max(ans,i - x + 1);
        }
        return ans;
    }
};