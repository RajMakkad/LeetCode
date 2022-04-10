class Solution {
public:
    int calPoints(vector<string>& ops){
        vector<int> s;

        for(auto i:ops){
            if(i == "+"){
                int n = s.size();
                s.push_back(s[n - 1] + s[n - 2]);
            }
            else if(i == "C") s.pop_back();
            else if(i == "D") s.push_back(2*s.back());
            else{
                int num = stoi(i);
                s.push_back(num);
            }
        }
        
        int sum = 0;
        for(int i:s) sum += i;
        return sum;
    }
};