class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> mp;
        
        for(int i = 0;i < n;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i:mp){
            vector<string> sub;
            for(int k = 0;k < i.second.size();k++){
                sub.push_back(strs[i.second[k]]);
            }
            
            ans.push_back(sub);
        }
        
        return ans;
    }
};