// METHOD 1: TIME = O(N * LOGN)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(auto it : nums) mp[-1 * it] ++;
        for(auto it : mp){
            int num = it.first, freq = it.second;
            while(freq > 0 and k != 0){
                freq --; k --;
            }
            if(freq >= 0 and k == 0) return -1 * num;
        }
        return -1;
    }
};

// METHOD 2: TIME = O(N * LOGK)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i < n; i ++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// METHOD 3: TIME = O(N * LOGN + K * LOGN)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();
        for(auto it : nums) pq.push(it);
        int ans;
        for(int i = 0; i < k; i ++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

// METHOD 4: TIME = O(N) = AVERAGE CASE, O(N ^ 2) = WORST CASE

/*
here we use the concept of quick select in which we use the partition method of 
quick sort and once we place the pivot index on the correct index then we check if
(n - k) == pivot then we found the number but if (n - k) < pivot element then we are
sure that the (n - k)th element will be on the left of pivot element because the 
pivot element is at it's correct postion in the final sorted array.

so we first partition the array and then go to either the left half of the array or 
the right half of the array.

*/

class Solution {
public:
    
    int ans = INT_MAX;
    
    int Partition(int n, int k, vector<int> &nums, int low, int high){
        int i = low, j = high;
        int pivot = nums[low];
        while(i < j){
            while(nums[i] <= pivot) i ++;
            while(nums[j] > pivot) j --;
            if(i < j) swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[low]);
        cout << j << endl;
        return j;
    }
    
    void QuickSort(int n, int k, vector<int> &nums, int low, int high){
        if(low == high){
            ans = nums[low]; return;
        }
        int pivot = Partition(n, k, nums, low, high);
        if((n - k) == (pivot - 1)){
            ans = nums[pivot]; return;
        }
        if((n - k) < (pivot - 1)) QuickSort(n, k, nums, low, pivot - 1);
        else QuickSort(n, k, nums, pivot + 1, high);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        QuickSort(n, k, nums, 0, n - 1);
        return ans;
    }
};

