class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int up = 1;
        int down = 0;

        for(int i = 1;i<n;i++){
            if(arr[i] > arr[i - 1]){
                if(down == 0) up++;
                else{
                    up = 2;
                    down = 0;
                }
            }
            else if(arr[i] < arr[i - 1]){
                down++;
                if(up >= 2 )ans = max(ans,up + down);
            }
            else{
                up = 1;
                down = 0;
            }
        }

        return ans;
    }
};