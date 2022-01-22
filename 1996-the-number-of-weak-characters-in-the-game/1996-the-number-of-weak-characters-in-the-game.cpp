class Solution {
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& p){
        sort(p.begin(),p.end(),comp);
        int n = p.size();
        int ans = 0;
        int e = n - 1;

        for(int i = n - 1;i>=0;i--){
            if(p[i][0] < p[e][0] and p[i][1] < p[e][1]) ans++;
            else e = i;
        }

        return ans;
    }
};