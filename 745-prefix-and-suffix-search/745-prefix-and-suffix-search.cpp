class WordFilter {
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& w) {
        for(int i = 0;i < w.size(); i++){
            string s = "";
            for(int j = 0; j< w[i].size(); j++){
                s += w[i][j];
                for(int k = 0; k < w[i].size(); k++){
                    string sub = s + '|' + w[i].substr(k, w[i].size() - k);
                    mp[sub] = i + 1;
                }
            }
        }
    }
    
    int f(string p, string s) {
        string ans = p + '|' + s;
        return mp[ans] - 1;
    }
};
