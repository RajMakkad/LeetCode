class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, a = 0, b = 0;
        for(auto num: nums)
            x = x ^ num;
        int bit = 1;
        while((x & 1) == 0){
            bit = bit << 1;
            x = x >> 1;
        }
        
        for(auto num: nums){
            if((num & bit))
                a = a ^ num;
            else
                b = b ^ num;
        }
        return {a, b};
    }
};