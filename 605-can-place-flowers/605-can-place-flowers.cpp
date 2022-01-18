class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n){
        int size = flowerbed.size();
        int index = -1;
        int cnt = 0;
        
        for(int i = 0;i<size;i++){
            if(flowerbed[i]){
                if(index == -1) cnt += i/2;
                else cnt += (i - index - 2)/2;
                index = i;
            }
        }
        
        if(index == -1) cnt += (size + 1)/2;
        else cnt += (size - index -1)/2;
        
        return cnt >= n;
    }
};