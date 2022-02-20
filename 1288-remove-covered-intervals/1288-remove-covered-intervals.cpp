class Solution{
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end(),comp);
        int s = intervals[0][0];
        int e = intervals[0][1];
        int ans = 1;

        for(auto &i:intervals){
            if(e >= i[1]) continue;
            else s = i[0] , e = i[1] , ans++;
        }

        return ans;
    }
};