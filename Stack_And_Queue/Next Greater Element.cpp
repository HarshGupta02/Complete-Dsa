/// HERE WE CHECK IF THE CURRENT ELEMENT CAN BE A GREATER ELEMENT FOR THE PREVIOUS
/// OCCURED ELEMENTS AND IF CAN BE THEN ASSIGN THEM THIS VALUE . THIS ENSURES THAT
/// IF NOW SOMEOTHER ELEMENT WHICH OCCURS AFTER THE CURRENT ELEMENT AND HAS VALUE
/// GREATER THAN THE ASSIGNED VALUE , THEN IT WILL NOT BE THE ANS BECAUSE THE CURRENT
/// ELEMENT CAME FIRST.


/// TIME = O(N)
// EACH ELEMENT WILL BE INSERTED ONCE AND DELETED ONCE.


class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    using ll = long long int;
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<ll>stk;
        vector<ll>ans(n);
        for(int i = 0 ; i < n ; i ++){
            while(!stk.empty() and arr[i] > arr[stk.top()]){
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