class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0;
        int one = 0;
        int idx = 0;
        int n = students.size();
        
        for(int i = 0;i < n;i++){
            if(students[i] == 1)
                one++;
            else
                zero++;
        }
        
        while(idx < n) {
            if(sandwiches[idx] == 1){
                if(one > 0) {
                    one--;
                }
                else {
                    break;
                } 
            }
            else if(sandwiches[idx] == 0){
                if(zero > 0) {
                    zero--;
                }
                else {
                    break;
                }
            }
            idx++;
        }
        return n - idx;
    }
};