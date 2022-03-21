class Solution {
    bool isValid(string &a,string &b){
        int cnt = 0;
        for(int i = 0;i<8;i++){
            cnt += (a[i] != b[i]);
        }
        return cnt == 1;
    }

public:
    int minMutation(string start, string end, vector<string>& bank){
        bank.push_back(start);
        int n = bank.size();

        vector<int> dist(n,1e9);
        dist[n - 1] = 0;

        queue<int> q;
        q.push(n - 1);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(bank[node] == end) return dist[node];
            for(int i = 0;i<n;i++){
                if(i != node and dist[i] > dist[node] + 1 and isValid(bank[node],bank[i])){
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }

        return -1;
    }
};