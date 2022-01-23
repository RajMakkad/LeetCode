class Solution {
public:
    vector<int> sequentialDigits(int low, int high){
        int N = 9;
        vector<int> nums;

        for(int i = 1;i<=N;i++){
            int num = 0;
            for(int s = i;s<=N;s++){
                num = num*10 + s;
                if(num >= low and high >= num) nums.push_back(num);
                if(num >= high) break;
            }
        }
        
        sort(nums.begin(),nums.end());
        return nums;
    }
};