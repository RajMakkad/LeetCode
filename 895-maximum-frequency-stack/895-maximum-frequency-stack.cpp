class FreqStack{
    map<int,stack<int>> f_s;
    map<int,int> count;
    int max_f;
public:
    FreqStack(){
        max_f = 0;
    }
    
    void push(int val){
        max_f = max(max_f,++count[val]);
        f_s[count[val]].push(val);
    }
    
    int pop(){
        int ans = f_s[max_f].top();
        f_s[max_f].pop();
        count[ans]--;
        if(f_s[max_f].empty()) max_f--;
        return ans;
    }
};