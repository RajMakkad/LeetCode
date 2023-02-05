class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26, 0), v2(26, 0), ans;
        
        for(auto &i: p){
            v1[i - 'a']++;
        }
        
        int n = s.length();
        int m = p.length();
        
        for(int i = 0;i < n;i++){
            v2[s[i] - 'a']++;
            
            if(i >= m - 1){
                if(v1 == v2)
                    ans.push_back(i - m + 1);
                
                v2[s[i - m + 1] - 'a']--;
            }
        }
        
        return ans;
    }
};