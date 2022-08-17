class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        
        for(auto w:words){
            string s = "";
            for(int i = 0;i < w.length();i++){
                int x = w[i] - 'a';
                s += v[x];
            }
            st.insert(s);
        }
        
        return st.size();
    }
};