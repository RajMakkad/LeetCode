class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int>(26, 0));
        for(auto &s: votes){
            int n = s.length();
            for(int i = 0;i < n;i++){
                count[(s[i] - 'A')][i]++;
            }
        }
        string s = votes[0];
        sort(s.begin(), s.end(), [&](char a, char b){
            for(int i = 0;i < s.length();i++){
                if(count[(a - 'A')][i] > count[(b - 'A')][i])
                    return true;
                if(count[(a - 'A')][i] < count[(b - 'A')][i])
                    return false;
            }
            return a < b;
        });
        return s;
    }
};