class Solution {
    bool is_possible(int &p,vector<int> &piles,int &h){
        int hours = 0;
        for(auto &i:piles){
            hours += (i + p - 1)/p;
        }

        return h >= hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 1e9;
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;
            if(is_possible(m,piles,h)) e = m - 1;
            else s = m + 1;
        }

        return s;
    }
};