class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(58,0),cur(58,0);
        pair<int,int> ans = {1e6,0};

        for(auto &i:t) cnt[i - 'A']++;
        int n = s.length();
        int start = 0;

        for(int end = 0;end <n;end++){
            cur[s[end] - 'A']++;
            int pass = 1;

            while(pass){
                for(int i = 0;i<58;i++){
                    if(cur[i] < cnt[i]){
                        pass = 0;
                        break;
                    }
                }

                if(pass){
                    if(end - start + 1 < ans.first) ans = {end - start + 1,start};
                    cur[s[start++] - 'A']--;
                }
            }
        }

        string str = "";
        if(ans.first != 1e6) str = s.substr(ans.second,ans.first);
        return str;
    }
};