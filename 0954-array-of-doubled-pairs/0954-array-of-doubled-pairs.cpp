class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s;
        for(auto &i: arr) 
            if(i >= 0)
                s.insert(i);
        
        while(!s.empty()){
            auto x = *s.begin();
            s.erase(s.find(x));
            
            if(s.find(2 * x) == s.end())
                return false;
            
            s.erase(s.find(2 * x));
        }
        
        for(auto &i: arr) 
            if(i < 0)
                s.insert(i);
        
        while(!s.empty()){
            auto x = *s.begin();
            s.erase(s.find(x));
            
            if(s.find(x / 2) == s.end() || x % 2)
                return false;
            
            s.erase(s.find(x / 2));
        }
        
        return true;
    }
};