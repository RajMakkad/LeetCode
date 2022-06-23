bool comp(const vector<int> &a,const vector<int> &b){
	// if(a[1] == b[1]) return a[0] > b[0];
	return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
		int ans = 1;
		int n = points.size();
		int end = points[0][1];

		for(int i = 1;i<n;i++){
			if(end < points[i][0]){
				ans++;
				end = points[i][1];
			}
		}

		return ans;
    }
};