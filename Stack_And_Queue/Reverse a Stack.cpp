/// METHOD 1: TIME : O(N) , SPACE = O(N)

// here it is assumed that the given stack has top as the rightmost 
// element.

// here we have not reversed the original stack but put the result in 
// some other data structure.

class Solution{
public:
    void f(stack<int>&st , vector<int>&ans){
        if(st.size() == 0) return;
        int x = st.top();
        ans.push_back(x);
        st.pop();
        f(st,ans);
    }

    vector<int> Reverse(stack<int> St){
        vector<int>ans;
        f(St,ans);
        return ans;
    }
};

// METHOD 2: WE USE THE CONCEPT OF INSERT AT BOTTOM FOR EACH ELEMENT THAT
// WAS LAST POPPED OUT FINALLY IN THE RECURSION STACK.

// TIME : O(N ^ 2) , SPACE = ???

class Solution{
public:

    void insert_at_bottom(stack<int> &stk , int x){
        if(stk.empty()){
            stk.push(x); return;
        }
        int y = stk.top();
        stk.pop();
        insert_at_bottom(stk,x);
        stk.push(y);
    }

    void f(stack<int> &stk){
        if(stk.empty()) return;
        int x = stk.top();
        stk.pop();
        f(stk);
        insert_at_bottom(stk , x);
    }

    vector<int> Reverse(stack<int> St){
        // vector<int>ans;
        f(St);
        // while(!St.empty()){
            // ans.push_back(St.top());
            // St.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};


