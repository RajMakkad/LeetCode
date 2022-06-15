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
    int memoization(int x, vector<int> &dp, vector<string> &w){
        if(dp[x] != -1) return dp[x];

        int ans = 0;
        for(int i = x + 1; i < w.size(); i++){
            if(w[i].size() > w[x].size() + 1) break;

            if(w[i].size() == w[x].size() + 1 and isChain(w[x], w[i])){
                ans = max(ans, memoization(i, dp, w));
            }
        }

        return dp[x] = ans + 1;
    }
public:
    int longestStrChain(vector<string>& w) {
        int n = w.size();
        vector<int> dp(n + 1, -1);
        sort(w.begin(), w.end(), comp);

        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, memoization(i, dp, w));
        }

        return ans;
    }
};