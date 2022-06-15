class Solution {
    static bool comp(const string &a, const string &b){
        return a.length() < b.length();
    }

    bool isChain(string &a, string &b){
        int x = 0, y = 0;
        while(x < a.length() and y < b.length()){
            if(a[x] == b[y]){
                x++, y++;
            }
            else y++;
        }

        return x == a.length();
    }
public:
    int longestStrChain(vector<string>& w) {
        int n = w.size();
        vector<int> dp(n, 0);
        sort(w.begin(), w.end(), comp);

        int ans = 0;

        for(int i = n - 1; i >= 0; i--){
            int sum = 0;
            for(int j = i + 1;j < n;j++){
                if(w[i].length() + 1 < w[j].length()) break;
                
                if(w[i].length() + 1 == w[j].length() and isChain(w[i], w[j])){
                    sum = max(sum, dp[j]);
                }
            }

            dp[i] = sum + 1;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};