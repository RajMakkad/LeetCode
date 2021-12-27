class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        
        for(int i = 0;i<n;i++){
            unordered_map<double,int> mp;
            for(int it = 0;it<n;it++){
                if(i == it) continue;
                double slope = 0;
                
                if(points[it][1] == points[i][1]) slope = 0;
                else if(points[it][0] == points[i][0]) slope = 1e9;
                else{
                    slope = (double)(points[it][1] - points[i][1]);
                    slope /= (double)(points[it][0] - points[i][0]);
                }
                
                mp[slope]++;
                ans = max(ans,mp[slope] + 1);
            }
        }
        return ans;
    }
};