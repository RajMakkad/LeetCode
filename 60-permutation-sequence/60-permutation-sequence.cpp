class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1;i<=n;i++){
            char c = i + '0';
            s += c;
        }

        vector<int> f(n,1);
        for(int i = 1;i<n;i++)  f[i] = f[i - 1] * i;

        for(int i = 0;i<n;i++){
            int x = f[n - i - 1];
            int y = 0;
            int idx = i - 1;

            while(k > y){
                y += x;
                idx++;
            }

            y = y - x;
            k = k - y;

            swap(s[i],s[idx]);
            sort(s.begin() + i + 1,s.end());
        }

        return s;
    }
};