class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int d = 0;
        int curr = 0;
        int index = 0;
        
        for(int i = 0;i<n;i++){
            d += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            
            if(curr < 0){
                index = i + 1;
                curr = 0;
            }
        }
        
        return d >= 0 ? index : -1;
    }
};