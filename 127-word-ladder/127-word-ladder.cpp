class Solution {
    bool is_able(string &a,string &b){
        int n = a.length();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(a[i] != b[i]) cnt++;
        }

        return cnt > 1 ? 0 : 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        wordList.push_back(beginWord);
        int n = wordList.size();

        vector<int> ans(n,1e9);
        ans[n - 1] = 1;
        
        queue<int> q;
        q.push(n - 1);

        while(q.size()){
            int node = q.front();
            q.pop();

            for(int i = 0;i<n;i++){
                if(i != node and ans[i] > ans[node] + 1 and is_able(wordList[i],wordList[node])){
                    ans[i] = ans[node] + 1;
                    q.push(i);
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            if(ans[i] != 1e9 and wordList[i] == endWord) return ans[i];
        }

        return 0;
    }
};