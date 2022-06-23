class Solution {
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), comp);
        priority_queue<int> q;
        int days = 0;
        
        for(int i = 0;i < c.size();i++){
            days += c[i][0];
            q.push(c[i][0]);
            
            if(days > c[i][1]){
                days = days - q.top();
                q.pop();
            }
        }
        return (int)q.size();
    }
};