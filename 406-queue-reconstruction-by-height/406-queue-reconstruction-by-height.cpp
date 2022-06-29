class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), comp);

        vector<vector<int>> ans(n);

        for(int i = 0;i < n;i++){
            int idx = people[i][1];

            for(int k = 0;k < n;k++){
                if(idx == 0 and ans[k].empty()){
                    ans[k] = people[i];
                    break;
                }

                if(ans[k].empty() || ans[k][0] >= people[i][0]) idx--;
            }
        }

        return ans;
    }
};