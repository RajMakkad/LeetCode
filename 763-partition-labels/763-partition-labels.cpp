class Solution {
public:
    vector<int> partitionLabels(string s){
        int n = s.length();
        vector<int> pos(26,0),ans;

        for(int i = 0;i<n;i++) pos[s[i] - 'a'] = i;
        int cnt = 0;
        int sum = 0;

        for(int i = 0;i<n;i++){
            cnt = max(cnt,pos[s[i] - 'a']);
            if(cnt == i){
                ans.push_back(cnt + 1 - sum);
                sum += ans.back();
            }
        }

        return ans;
    }
};