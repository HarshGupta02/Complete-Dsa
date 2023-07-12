class Solution{
    public:
    
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = n/2 - 1; i >= 0; i --) {
            int left = 2*i + 1, right = 2*i + 2;
            int largest = i;
            if(left < n and arr[largest] < arr[left]) largest = left;
            if(right < n and arr[largest] < arr[right]) largest = right;
            if(largest != i) return false;
        }
        return true;
    }
};