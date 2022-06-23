bool findPair(int arr[], int size, int n){
    sort(arr , arr + size);
    int left = 0 , right = 0; 
    while(left < size){
        if(left == right){
            right ++; continue;
        }
        int curr_diff = arr[right] - arr[left];
        if(curr_diff == n) return true;
        if(curr_diff < n){
            right ++;
        }else{
            left ++;
        }
    }
    return false;
}