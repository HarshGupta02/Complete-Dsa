class Solution{
    public:
    int search(int A[], int l, int h, int key){
        int low = l , high = h;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] == key) return mid;
            if(A[low] <= A[mid]){
                if(key >= A[low] and key <= A[mid]) high = mid - 1;
                else low = mid + 1;
            }else{
                if(key >= A[mid] and key <= A[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};