class Solution {    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> rangeQuery(1001,0);

        for(auto i:trips){
            rangeQuery[i[1]] += i[0];
            rangeQuery[i[2]] -= i[0];
        }

        if(rangeQuery[0] > capacity) return false;

        for(int i = 1;i<=1000;i++){
            rangeQuery[i] += rangeQuery[i - 1];
            if(rangeQuery[i] > capacity) return false;
        }

        return true;
    }
};