// TIME = O(N * LOGK) , SPACE = O(K)

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>pq;
        int n = r + 1;
        for(int i = 0 ; i < n ; i ++){
            pq.push(arr[i]);
            if(pq.size() == k + 1) pq.pop();
        }
        return pq.top();
    }
};