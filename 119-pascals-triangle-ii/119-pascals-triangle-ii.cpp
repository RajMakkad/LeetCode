class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long int ans = 1;
        
        vector<int> row = {1};
        
        for(int i = 0;i<rowIndex;i++){
            ans *= (rowIndex-i);
            ans /= (i+1);
            row.push_back((int)ans);
        }
        return row;
    }
};