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

// METHOD 2:

class MyQueue {
public:
    stack<int> in, out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int x = out.top(); out.pop();
        return x;
    }
    
    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() and out.empty();
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