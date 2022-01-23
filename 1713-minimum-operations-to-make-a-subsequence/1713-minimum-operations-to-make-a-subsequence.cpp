class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& a) {
        int n = target.size();
        int m = a.size();
        map<int,int> index;

        for(int i = 0;i<n;i++) index[target[i]] = i;
        vector<int> seq;

        for(int i = 0;i<m;i++){
            if(index.find(a[i]) != index.end()){
                if(seq.empty() || index[a[i]] > seq.back()) seq.push_back(index[a[i]]);
                else{
                    int l = lower_bound(seq.begin(),seq.end(),index[a[i]]) - seq.begin();
                    seq[l] = index[a[i]];
                }
            }
        }

        return n - (int)seq.size();
    }
};