class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        int n = w.size(), ans = 0;
        unordered_set<string> s(w.begin(), w.end());

        for(string i:s){
            for(int k = 1;k < i.length();k++){
                s.erase(i.substr(k));
            }
        }

        for(string i:s){
            ans += i.length() + 1;
        }
        return ans;
    }
};