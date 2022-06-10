class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
    }
    
    int book(int s, int e) {
        mp[s]++;
        mp[e]--;

        int cnt = 0;
        int ans = 0;
        
        for(auto &i:mp){
            cnt += i.second;
            ans = max(ans, cnt);
        }

        return ans;
    }
};