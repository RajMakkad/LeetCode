class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        map<char,int> mp1,mp2;
        
        for(auto i:s) mp2[i]++;
        for(auto i:s){
            mp1[i]++;
            mp2[i]--;
            if(mp2[i] == 0) mp2.erase(i);
            if(mp1.size() == mp2.size()) ans++;
        }
        
        return ans;
    }
};