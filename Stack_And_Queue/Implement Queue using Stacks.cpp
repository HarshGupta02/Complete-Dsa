class MyQueue {
public:
    
    stack<int>stk1, stk2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!stk2.empty()){
            int curr = stk2.top(); stk2.pop();
            stk1.push(curr);
        }
        stk1.push(x);
    }
    
    int pop() {
        while(!stk1.empty()){
            int curr = stk1.top(); stk1.pop();
            stk2.push(curr);
        }
        if(stk2.empty()) return -1;
        int temp = stk2.top(); stk2.pop();
        return temp;
    }
    
    int peek() {
        while(!stk1.empty()){
            int curr = stk1.top(); stk1.pop();
            stk2.push(curr);
        }
        if(stk2.empty()) return -1;
        return (int) stk2.top();
    }
    
    bool empty() {
        if(stk1.empty() and stk2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */