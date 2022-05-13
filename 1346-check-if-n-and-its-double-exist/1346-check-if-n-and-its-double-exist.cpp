class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i = 0;i<a.size();i++){
            int s = 0;
            if(a[i] == 0) s = i + 1;
            if(binary_search(a.begin() + s,a.end(),2*a[i])) return true;
        }
        
        return false;
    }
};