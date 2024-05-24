class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int ans = 0;
        vector<int> count(26,0);
        
        for(auto i:letters) count[i - 'a']++;
        
        int end = (1LL<<n);
        for(int it1 = 0;it1<end;it1++){
            int c = 1;
            int sum = 0;
            vector<int> sub(26,0);
            for(int it2 = 0;it2<n;it2++){
                if((it1&(1LL<<it2))){
                    for(auto i:words[it2]){
                        sub[i - 'a']++;
                        if(sub[i - 'a'] > count[i - 'a']){
                            c = 0;
                            break;
                        }
                        sum += score[i - 'a'];
                    }
                    if(c==0) break;
                }
                if(c==0) break;
            }
            if(c) ans = max(ans,sum);
        }
        
        return ans;
    }
};