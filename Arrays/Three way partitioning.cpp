class Solution{   
public:

    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n = arr.size();
        int low = 0 , mid = 0 , high = n - 1;
        while(mid <= high){
            if(arr[mid] < a){
                swap(arr[mid] , arr[low]);
                low ++; mid ++; continue;
            }
            if(arr[mid] >= a and arr[mid] <= b){
                mid ++; continue;
            }
            if(arr[mid] > b){
                swap(arr[mid] , arr[high]);
                high --; continue;
            }
        }
    }
};