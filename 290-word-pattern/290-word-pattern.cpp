class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s += " ";
        int n = s.length();
        vector<string> vs;
        string sub = "";

        for(int i = 0;i<n;i++){
            if(s[i] == ' '){
                vs.push_back(sub);
                sub = "";
            }
            else sub += s[i];
        }

        if(pattern.size() != vs.size()) return false;

        n = pattern.size();
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(pattern[i] == pattern[j]){
                    if(vs[i] != vs[j]) return false;
                }
                else if(vs[i] == vs[j]) return false;
            }
        }

        return true;
    }
};