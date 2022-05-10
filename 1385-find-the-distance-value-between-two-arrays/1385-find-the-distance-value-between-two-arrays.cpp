class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int distanceValue = 0;
        int pointer_one = -1;
        int pointer_two = -1;
        
        for (int pointer_one = 0; pointer_one < arr1.size(); pointer_one++) {
            pointer_two = 0;
            bool addNum = true;
            for (int pointer_two = 0; pointer_two < arr2.size(); pointer_two++) {
                if (abs(arr1[pointer_one] - arr2[pointer_two]) <= d)
                    addNum = false;
            }
            if (addNum)
                distanceValue++;
        }
        
        return distanceValue;
    }
};