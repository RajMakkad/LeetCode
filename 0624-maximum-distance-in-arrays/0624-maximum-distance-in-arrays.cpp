class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min_ = arrays[0].front();
        int max_ = arrays[0].back();
        int distance = 0;
        for(int i = 1; i < n; i++){
            distance = max({distance, abs(arrays[i].back() - min_), abs(max_ - arrays[i].front())});
            min_ = min(min_, arrays[i].front());
            max_ = max(max_, arrays[i].back());
        }
        return distance;
    }
};