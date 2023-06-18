/*
so basically we keep on pushing the current element into the stack of the current frequency
of the element. so we put all the elements that belong to a certain frequency.

*/

class FreqStack {
public:
    map<int, vector<int>> f1;
    map<int, int> f2;
    int max_f = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        f2[val] ++;
        max_f = max(max_f, f2[val]);
        f1[f2[val]].push_back(val);
    }
    
    int pop() {
        int res = f1[max_f].back();
        f1[max_f].pop_back();
        f2[res] --;
        if(f1[max_f].size() == 0) {
            f1.erase(max_f);
            max_f --;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */