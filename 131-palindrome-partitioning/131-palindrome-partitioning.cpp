class Solution {
    vector<vector<string>> ans;
    void generate(int &start,string &s,vector<vector<int>> &p,vector<string> &sub){
        int n = s.length();
        if(start >= n){
            ans.push_back(sub);
            return ;
        }

        for(int end = start;end<n;end++){
            if(p[start][end]){
                sub.push_back(s.substr(start,end - start + 1));
                end++;
                generate(end,s,p,sub);
                end--;
                sub.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string str) {
        int n = str.length();
        vector<vector<int>> p(n,vector<int>(n,0));

        for(int g = 0;g<n;g++){
            for(int s = 0;s + g <n;s++){
                int e = s + g;
                if(g == 0) p[s][e] = 1;
                else if(g == 1 and str[s] == str[e]) p[s][e] = 1;
                else if(str[s] == str[e] and p[s + 1][e - 1]) p[s][e] = 1; 
            }
        }

        vector<string> sub;
        int start = 0;
        generate(start,str,p,sub);
        
        return ans;
    }
};