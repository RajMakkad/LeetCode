#define ff first
#define ss second

class MyCalendar {
    vector<pair<int, int>> v;
public:
    MyCalendar() {
        v.clear();
    }
    
    bool book(int s, int e) {
        int n = v.size();
        for(int i = 0;i < n;i++){
            if(v[i].ff >= s and e > v[i].ff) return false;
            if(v[i].ff <= s and v[i].ss > s) return false;
        }
        
        v.push_back({s, e});
        return true;
    }
};
