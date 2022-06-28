class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        for(int i = 0;i < n;i++){
            int x = s[i] - 'a';
            freq[x]++;
        }
        
        sort(freq.begin(), freq.end());
        
        int ans = 0;
        
        for(int i = 24;i >= 0;i--){
            if(freq[i] == 0) break;
            
            if(freq[i] >= freq[i + 1]){
                int p = max(freq[i + 1] - 1, 0);
                ans += freq[i] - p;
                freq[i] = p;
            }
        }
        
        return ans;
    }
};