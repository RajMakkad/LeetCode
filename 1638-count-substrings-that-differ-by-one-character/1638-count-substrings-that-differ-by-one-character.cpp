class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();

        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int miss = 0;
                for(int k = 0;k + i < m and k + j < n;k++){
                    if(s[j + k] != t[i + k]){
                        miss++;
                        if(miss > 1) break;
                    }

                    ans += miss;
                }
            }
        }

        return ans;
    }
};