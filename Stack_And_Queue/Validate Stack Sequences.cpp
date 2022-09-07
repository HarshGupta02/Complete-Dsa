// METHOD 1: TIME = O(N), SPACE = O(N)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>stk;
        int i = 0, idx = 0;
        for(int i = 0; i < n; i ++){
            stk.push(pushed[i]);
            while(!stk.empty() and stk.top() == popped[idx]){
                stk.pop(); idx ++;
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};

// METHOD 2: TIME = O(N), SPACE = O(1)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        for(auto val : pushed){
            pushed[i ++] = val;
            while(i > 0 and pushed[i - 1] == popped[j]){
                i --; j ++;
            }
        }
        return i == 0;
    }
};