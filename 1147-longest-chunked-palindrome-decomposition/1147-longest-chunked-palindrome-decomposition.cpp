class Solution {
public:
    int longestDecomposition(string text) {
        int s = 0;
        int e = text.length() - 1;
        int count = 0;

        string str = "";

        while(e >= s){
            str += text[s];
            if(text[s] == text[e] and str == text.substr(e - str.size() + 1,str.size())){
                if(s != e) count += 2;
                else count++;
                e = e - str.size();
                str = "";
            }
            s++;
        }

        return count;
    }
};