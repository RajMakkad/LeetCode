class Solution {
    struct Node{
        Node *link[26];
        int count = 0;
        int end = 0;
    };
    
    Node *root = new Node();
    
    void add(string &s){
        Node *node = root;
        for(auto &i: s){
            int x = i - 'a';
            
            if(!node->link[x])
                node->link[x] = new Node();
            
            node = node->link[x];
            node->count++;
        }
        
        node->end++;
    }
    
    void remove(string &s){
        Node *node = root;
        for(auto &i: s){
            int x = i - 'a';
            
            node = node->link[x];
            node->count--;
        }
        
        node->end--;
    }
    
    int solve(int idx, int &n, string &s, vector<int> &dp){
        if(idx >= n)
            return 1;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        Node *node = root;
        int ans = 0;
        
        for(int i = idx;i < n;i++){
            node = node->link[s[i] - 'a'];
            
            if(!node || !node->count)
                break;
            
            if(node->end > 0)
                ans |= solve(i + 1, n, s, dp);
        }
        
        return dp[idx] = ans;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &w: words)
            add(w);
        
        vector<string> ans;
        
        for(auto &w: words){
            remove(w);
            
            int n = w.length();
            vector<int> dp(n, -1);
            
            if(solve(0, n, w, dp))
                ans.push_back(w);
            
            add(w);
        }
        
        return ans;
    }
};