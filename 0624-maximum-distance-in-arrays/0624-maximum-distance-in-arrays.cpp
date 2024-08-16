class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int m = arrays[0].size();
        vector<pair<int, int>> min_, max_;
        for(int i = 0; i < n; i++){
            min_.push_back({arrays[i].front(), i});
            max_.push_back({arrays[i].back(), i});
        }
        
        sort(min_.begin(), min_.end());
        sort(max_.begin(), max_.end());
        if(min_[0].second == max_[n - 1].second)
            return max(max_[n - 2].first - min_[0].first, max_[n - 1].first - min_[1].first);
        return max_[n - 1].first - min_[0].first;
    }
};