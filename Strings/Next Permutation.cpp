class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int idx = -1;
        for(int i = N - 2; i >= 0; i--){
            if(arr[i] >= arr[i + 1]) continue;
            idx = i; break;
        }
        if(idx == -1){
            sort(arr.begin(), arr.end());
            return arr;
        }
        for(int i = N - 1; i >= 0; i --){
            if(arr[i] > arr[idx]){
                swap(arr[i] , arr[idx]);
                break;
            }
        }
        sort(arr.begin() + idx + 1, arr.end());
        return arr;
    }
};