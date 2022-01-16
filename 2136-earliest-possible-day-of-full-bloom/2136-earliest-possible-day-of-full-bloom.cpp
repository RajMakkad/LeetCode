class Solution {
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        return a.second > b.second;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime){
        int n = plantTime.size();
        vector<pair<int,int>> p(n);

        for(int i = 0;i<n;i++){
            p[i] = {plantTime[i],growTime[i]};
        }

        sort(p.begin(),p.end(),comp);
        int s = 0;
        int ans = 0;

        for(int i = 0;i<n;i++){
            s += p[i].first;
            ans = max(ans,s + p[i].second);
        }

        return ans;
    }
};