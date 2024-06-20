class Solution {
    bool solve(int m, int n, int k, vector<int> &position){
        int idx = 0;
        k--;
        for(int i = 1; i < n; i++){
            if(position[i] >= position[idx] + m) {
                k--;
                idx = i;
            }
        }
        return k <= 0;
    }
public:
    int maxDistance(vector<int>& position, int k) {
        int n = position.size();
        sort(position.begin(), position.end());
        int s = 1, e = 1e9;
        int m = s + (e - s)/2;
        while(e >= s){
            m = s + (e - s)/2;
            if(solve(m, n, k, position))
                s = m + 1;
            else 
                e = m - 1;
        }
        return e;
    }
};