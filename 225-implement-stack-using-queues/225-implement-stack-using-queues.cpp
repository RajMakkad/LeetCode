class MyStack {
public:
    queue<int> q;
    MyStack() {
        return ;
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x;
        for(int i = 0;i<q.size() - 1;i++)
        {
            x = q.front();
            q.pop();
            q.push(x);
        }
        x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};