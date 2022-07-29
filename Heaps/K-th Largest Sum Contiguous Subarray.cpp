// METHOD 1: TIME = O(N * N * LOG K) , SPACE = O(N + K)

class Solution{
public:
    int kthLargest(vector<int> &a,int n,int k){
        vector<int>prefix_sum(n + 1,0);
        for(int i = 1; i <= n ; i ++){
            prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0; i < n ; i ++){
            for(int j = i ; j < n ; j ++){
                pq.push(prefix_sum[j + 1] - prefix_sum[i]);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};

// METHOD 2: TIME = O(N * N * LOG K) , SPACE = O(K)

class Solution{
public:
    int kthLargest(vector<int> &a,int n,int k){
        int sum = a[0];
        for(int i = 1; i < n ; i ++){
            sum += a[i];
            a[i] = sum;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0; i < n ; i ++){
            for(int j = i ; j < n ; j ++){
                if(i == 0) pq.push(a[j]);
                else pq.push(a[j] - a[i - 1]);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};