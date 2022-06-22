vector<int> find(int arr[], int n , int x )
{
    int first = -1 , last = -1;
    int low = 0 , high = n - 1;
    // first occurence
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            first = mid; high = mid - 1;
        }
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    low = 0 , high = n - 1;
    // last occurence
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            last = mid; low = mid + 1;
        }
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    vector<int>ans; 
    if(first == -1 or last == -1){
        ans.push_back(-1); ans.push_back(-1);
        return ans;
    }
    ans.push_back(first); ans.push_back(last);
    return ans;
}