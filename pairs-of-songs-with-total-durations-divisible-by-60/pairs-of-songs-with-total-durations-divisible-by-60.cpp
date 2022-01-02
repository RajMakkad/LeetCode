class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int sum = 0;
        map<int,int> count;
        
        for(auto i:time) count[i%60]++;
        
        for(auto i:count){
            if(i.first == 30 || i.first == 0) ans += i.second*(i.second - 1)/2;
            else sum += i.second*count[60 - i.first];
        }
        
        ans += sum/2;
        
        return ans;
    }
};