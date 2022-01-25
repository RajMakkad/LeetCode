class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n = a.size();
        int p = 1;
        
        for(int i = 1;i<n;i++){
            if(p == 1){
                if(a[i] > a[i - 1]) continue;
                else{
                    if(i == 1) return false;
                    p = 0;
                    i--;
                }
            }
            else{
                if(a[i] < a[i - 1]) continue;
                else return false;
            }
        }
        return n >= 3 and !p;
    }
};