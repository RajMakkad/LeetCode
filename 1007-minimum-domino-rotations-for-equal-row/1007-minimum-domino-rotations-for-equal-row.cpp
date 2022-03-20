class Solution {
    int makeConfig(int face,vector<int>& tops, vector<int>& bottoms){
        int n = tops.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(face != tops[i]){
                if(face == bottoms[i]) cnt++;
                else return 1e9;
            }
        }
        
        return cnt;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = 1e9;
        int b = 1e9;
        int c = 1e9;
        int d = 1e9;

        a = makeConfig(tops[0],tops,bottoms);
        b = makeConfig(tops[0],bottoms,tops);
        c = makeConfig(bottoms[0],tops,bottoms);
        d = makeConfig(bottoms[0],bottoms,tops);

        int ans = min({a,b,c,d});
        return ans == 1e9 ? -1 : ans;
    }
};