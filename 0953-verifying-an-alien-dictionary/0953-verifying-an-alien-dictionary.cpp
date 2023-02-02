class Solution {
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26, 0);
        
        for(int i = 0;i < 26;i++){
            v[order[i] - 'a'] = i;
        }
        
        for(auto &i: words){
            for(auto &c: i){
                c = v[c - 'a'] + 'a';
            }
        }
        
        return is_sorted(words.begin(), words.end());
    }
};