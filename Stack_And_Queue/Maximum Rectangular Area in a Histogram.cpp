// METHOD 1: TIME : O(N) ~ 2 PASSES, SPACE = O(3 * N).

/*
for each element , try to find the first smaller element to the right and to the left and the
area covered btw both the left and the right will be area under consideration. 
*/

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    using ll = long long int;
    vector<ll> get_smaller_element_f(ll arr[],stack<ll> &stk , int n){
        vector<ll>v(n); // stores the first smaller element to the right.
        for(int i = 0; i < n ; i ++){
            if(stk.empty()){
                stk.push(i); continue;
            }
            while(!stk.empty() and arr[i] < arr[stk.top()]){
                v[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            v[stk.top()] = n;
            stk.pop();
        }
        return v;
    }
    
    vector<ll> get_smaller_element_b(ll arr[] , stack<ll> &stk , int n){
        vector<ll>v(n); // stores the first smaller element to the right.
        for(int i = n - 1; i >= 0 ; i --){
            if(stk.empty()){
                stk.push(i); continue;
            }
            while(!stk.empty() and arr[i] < arr[stk.top()]){
                v[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            v[stk.top()] = -1;
            stk.pop();
        }
        return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        stack<ll>stk;
        vector<ll>prefix = get_smaller_element_f(arr,stk,n);
        vector<ll>suffix = get_smaller_element_b(arr,stk,n);
        ll nax = -1;
        for(int i = 0; i < n ; i ++){
            ll curr = 0;
            curr = (prefix[i] - i) * arr[i] + (i - suffix[i]) * arr[i] - arr[i];
            nax = max(nax , curr);
        }
        return nax;
    }
};

// METHOD 2: TIME = O(N) ~ 1 PASS , SPACE = O(N)

/*
if the current element is less than stk.top(), then we know that the next smaller element in 
right of the stack's top will be curr a[i] and next smaller element in the left will be the 
element below the stack's top and so we will pop out the top of stack and keep doing it until 
our curr a[i] > a[stk.top()]. 

it is possible that some elements remain in the stack after processing all the elements , so we
will iterate till i == n as it will contribute 0 height. and so width = i - stk.top() - 1, if 
stack is not empty after removing top else if it becomes empty after removing the top so 
width = i.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int>stk;
        for(int i = 0; i <= n ; i ++){
            // if stack is not empty
            while(!stk.empty() and (i == n or heights[stk.top()] > heights[i])){
                int height = heights[stk.top()];
                stk.pop();
                int width;
                if(stk.empty()) width = i;
                else width = i - stk.top() - 1; // i tells the index of first smaller element on
                // the right and stk.top() tells the index of the first element on the left.
                ans = max(ans, width * height);
            }
            stk.push(i);
        }
        return ans;
    }
};