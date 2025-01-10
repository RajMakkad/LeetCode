class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26, 0);
        for(auto &i: words2){
            vector<int> tmp(26, 0);
            for(auto &ch: i){
                int c = ch - 'a';
                tmp[c]++;
                req[c] = max(req[c], tmp[c]);
            }
        }
        vector<string> ans;
        for(auto &i: words1){
            vector<int> tmp(26, 0);
            bool accept = true;
            for(auto ch: i){
                int c = ch - 'a';
                tmp[c]++;
            }
            for(int i = 0; i < 26; i++)
                if(tmp[i] < req[i]){
                    accept = false;
                    break;
                }
            if(accept)
                ans.push_back(i);
        }
        return ans;
    }
};