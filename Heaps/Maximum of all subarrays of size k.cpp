/*
so here we are trying to store the elements which lie strictly in the window
of size k in decreasing order and for each a[i] , we assign it's correct 
place by removing elements which are less than a[i] as they would never
contribute to the ans and then we look from the front and get the max element.
*/

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0; i < n ; i++){
            if(!dq.empty() and dq.front() == i - k) dq.pop_front();
            while(!dq.empty() and arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};