class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        
        for(int i = 0;i < s.length();i++){
            int x = s[i] - 'a';
            cnt[x]++;
        }
        
        for(int i = 0;i < s.length();i++){
            int x = s[i] - 'a';
            if(cnt[x] == 1) return i;
        }
        
        return -1;
    }
};