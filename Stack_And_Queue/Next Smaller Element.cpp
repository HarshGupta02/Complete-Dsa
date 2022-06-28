class Solution{
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int>stk;
        vector<int>ans(n);
        for(int i = 0; i < n ; i++){
            if(stk.empty()){
                stk.push(i); continue;
            }
            while(!stk.empty() and arr[stk.top()] > arr[i]){
                ans[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()] = -1;
            stk.pop();
        }
        return ans;
    } 
};