class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> hash(26,0),sub(26,0),ans;
        for(auto i:p) hash[i - 'a']++;

        for(int i = 0;i<n;i++){
            sub[s[i] - 'a']++;
            if(i>=m) sub[s[i - m] - 'a']--;
            if(hash==sub) ans.push_back(i - m + 1);
        }

        return ans;
    }
};