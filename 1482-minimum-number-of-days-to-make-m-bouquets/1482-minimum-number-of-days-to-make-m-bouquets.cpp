class Solution {
    bool is_possible(int mid, int m, int k, vector<int> &bloomDay){
        int count = 0;
        for(auto &i: bloomDay){
            if(mid >= i)
                count++;
            else
                count = 0;
            if(count >= k){
                count = 0;
                m--;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1, max_ = *max_element(bloomDay.begin(), bloomDay.end());
        int e = max_;
        int mid = s + (e - s)/2;
        while(e >= s){
            mid = s + (e - s)/2;
            if(is_possible(mid, m, k, bloomDay))
                e = mid - 1;
            else 
                s = mid + 1;
        }
        return s > max_ ? -1: s;
    }
};