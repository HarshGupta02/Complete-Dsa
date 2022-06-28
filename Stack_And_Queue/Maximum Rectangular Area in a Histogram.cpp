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