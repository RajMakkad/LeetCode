class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        multiset<int> s;
        for(int i = 0;i<hand.size();i++) s.insert(hand[i]);

        while(!s.empty()){
            int u = *s.begin();
            s.erase(s.find(u));

            int next = u + 1;
            int x = n - 1;
            while(x--){
                auto f = s.find(next);
                if(f == s.end()) return false;
                u = next++;
                s.erase(f);
            }
        }

        return true;
    }
};