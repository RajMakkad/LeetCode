class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        unordered_map<string,bool> end,vis;
        for(auto &i:deadends) end[i] = true;
        string node = "0000";
        int dist = 0;

        queue<string> q;
        if(!end[node]) q.push(node);
        vis[node] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                node = q.front();
                q.pop();

                if(node == target){
                    return dist;
                }

                for(int i = 0;i<4;i++){
                    int a = ((node[i] - '0') + 1)%10;
                    int b = ((node[i] - '0') - 1 + 10)%10;
                    char c = node[i];
                    
                    node[i] = a + '0';
                    if(!vis[node] and !end[node]){
                        q.push(node);
                        vis[node] = true;
                    }

                    node[i] = b + '0';
                    if(!vis[node] and !end[node]){
                        q.push(node);
                        vis[node] = true;
                    }

                    node[i] = c;
                }
            }
            
            dist++;
        }

        return -1;
    }
};