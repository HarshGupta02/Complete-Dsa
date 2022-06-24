class Solution{
using ll = long long int;
public:
    int findMissing(int arr[], int n) {
        int d = (arr[n - 1] - arr[0]) / n;
        int low = 0 , high = n - 1;
        while(high - low > 1){
            int mid = low + (high - low)/2;
            /// check if left half is AP or not.
            int possible_d = (arr[mid] - arr[low]) / (mid - low);
            if(possible_d == d and arr[low] + (possible_d * (mid - low)) == arr[mid]) low = mid;
            else high = mid;
        }
        return (arr[low] + arr[high]) / 2;
    }
};