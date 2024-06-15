class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> arr(n);
        priority_queue<int> q;
        for(int i = 0; i < n; i++)
            arr[i] = {capital[i], profits[i]};
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            int cap = arr[i].first;
            int prf = arr[i].second;
            while(cap > w and k > 0 and (int)q.size() > 0){
                int top = q.top();
                q.pop();
                w += top;
                k--;
            }
            if(cap > w)
                break;
            q.push(prf);
        }
        while(k > 0 and (int)q.size() > 0){
            int top = q.top();
            q.pop();
            w += top;
            k--;
        }
        return w;
    }
};