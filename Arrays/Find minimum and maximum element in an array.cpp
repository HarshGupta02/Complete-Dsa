//// TIME = O(N) , SPACE = O(1).

// no of comparisons => (WORST CASE) = 1 + 2*(n - 2) ; (BEST CASE) = 1 + 0 + (n - 2)

struct pair getMinMax(long long int arr[], long long int n) {
    // we should try to minimise the number of comparisons
    struct pair obj;
    long long int maxi , mini ;
    if(arr[0] > arr[1]){
        maxi = arr[0];  mini = arr[1];
    }else{
        maxi = arr[1];  mini = arr[0];
    } // we took maxi and mini as first 2 elements because it reduces the number of comparisons by 3(else would be 4).
    for(int i = 2 ; i < n ; i ++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    obj.max = maxi , obj.min = mini;
    return obj;
}


/// -----(TOURNAMENT METHOD) -----

//// we find the min and max of left and right subarray and then compare the min and max of bith the left and right subarray
//// and set the new min and max as the min and max of the whole subarray.

/// TIME = O(N) , (AUX)SPACE = O(LOG N)

/// TOTAL NUMBER OF COMPARISONS = 3*N/2 - 2 (IF N IS POWER OF 2) ELSE > (3 * N)/2 - 2;

//// T(N) = T(CEIL(N/2)) + T(FLOOR(N/2)) + 2;'


pair<ll,ll> f(ll low , ll high, ll a[]){
    pair<ll,ll>p;
    if(low == high){
        p.first = a[low]; p.second = a[low]; return p;
    }
    if(high == low + 1){
        if(a[low] > a[high]){
            p.first = a[high]; p.second = a[low]; return p;
        }else{
            p.first = a[low]; p.second = a[high]; return p;
        }
    }
    ll mid = low + (high - low) / 2;
    pair<ll,ll>p_left = f(low , mid , a);
    pair<ll,ll>p_right = f(mid + 1, high , a);
    if(p_left.first < p_right.first) p.first = p_left.first;
    else p.first = p_right.first;
    if(p_left.second > p_right.second) p.second = p_left.second;
    else p.second = p_right.second;
    return p;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<ll,ll> obj = f(0 , n - 1, a);
    return obj;
}



/// ------COMAPARE IN PAIRS -------- (BEST METHOD).......

/// TIME = O(N) , SPACE = O(1)

/// we take a min and max pair of first two elements if n = even or only first element if n is odd.
/// then we compare all pairs with the global pair of max and min and try to update it.

//// NUMBER OF COMPARISONS = (N = ODD) => 3*(N - 1)/2; ELSE (N = EVEN) => 1 + 3(N - 2)/2;

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<ll,ll>p;
    if(n % 2 == 0){
        if(a[0] > a[1]){
            p.first = a[1]; p.second = a[0];
        }else{
            p.first = a[0]; p.second = a[1];
        }
    }else{
        p.first = p.second = a[0];
    }
    int i = (n % 2 == 1) ? 1 : 2;
    while(i < n){
        if(a[i] > a[i + 1]){
            if(a[i] > p.second) p.second = a[i];
            if(a[i + 1] < p.first) p.first = a[i + 1];
        }else{
            if(a[i + 1] > p.second) p.second = a[i + 1];
            if(a[i] < p.first) p.first = a[i];
        }
        i += 2;
    }
    return p;
}
