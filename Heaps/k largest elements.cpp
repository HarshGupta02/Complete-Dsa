/// METHOD 1 : TIME = O(N * LOGK)

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int>pq;
	    for(int i = 0; i < k ; i ++){
	        pq.push(-1 * arr[i]);
	    } // K * LOGK
	    for(int i = k ; i < n ; i ++){
	        pq.push(-1 * arr[i]);
	        pq.pop();
	    } // (N - K) * LOGK
	    vector<int>ans;
	    while(!pq.empty()){
	        ans.push_back(-1 * pq.top());
	        pq.pop();
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};