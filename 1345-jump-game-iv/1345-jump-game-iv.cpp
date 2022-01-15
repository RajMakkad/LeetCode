class Solution {
public:
    int minJumps(vector<int>& a){
        int n = a.size();
        vector<int> steps(n,1e9);
        map<int,vector<int>> g;

        steps[0] = 0;

        for(int i = 0;i<n;i++){
            g[a[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        while(q.size()){
            int index = q.front();
            q.pop();

            if(index > 0 and steps[index - 1] > steps[index] + 1){
                q.push(index - 1);
                steps[index - 1] = steps[index] + 1;
            }

            if(index + 1 < n and steps[index + 1] > steps[index] + 1){
                q.push(index + 1);
                steps[index + 1] = steps[index] + 1;
            }

            int s = g[a[index]].size() - 1;
            for(int i = s;i>=0;i--){
                if(steps[g[a[index]][i]] > steps[index] + 1){
                    steps[g[a[index]][i]] = steps[index] + 1;
                    q.push(g[a[index]][i]);
                    g[a[index]].pop_back();
                }
            }
        }

        return steps[n - 1];
    }
};