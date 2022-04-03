class Solution {
    vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
public:
    long long sumScores(string s) {
        vector<int> z = z_function(s);
        z[0] = s.length();
        
        long long ans = 0;
        for(int i = 0;i<s.length();i++) ans += z[i];
        return ans;
    }
};