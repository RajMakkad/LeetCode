class Solution {
static bool comp(const vector<int> &a,const vector<int> &b){
	if(a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        int n = people.size();
        vector<vector<int>> q(n);
        sort(people.begin(),people.end(),comp);
        
        for(int i = 0;i<n;i++){
            int pos = people[i][1];
            for(int p = 0;p<n;p++){
                if(pos == 0 and q[p].empty()){
                    q[p] = people[i];
                    break;
                }
                
                if(q[p].empty() || q[p][0] >= people[i][0]) pos--;
            }
        }
        
        return q;
    }
};