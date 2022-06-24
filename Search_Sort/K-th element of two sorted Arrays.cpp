class Solution{
    public:
    using ll = long long int;
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) return kthElement(arr2 , arr1 , m , n , k);
        ////    ....... n........m........ so k < n or n < k < m or m < k
        ////    if k < n so low = 0 , high = k;
        ////    if n < k < m so low = 0 , high = n
        ////    if m < k so low = k - m , high = n
        int low = max(0 , k - m) , high = min(n , k);
        while(low <= high){
            int cut1 = low + (high - low)/2;
            int cut2 = k - cut1;
            ll l1 = (cut1 == 0) ? -1e18 : arr1[cut1 - 1];
            ll l2 = (cut2 == 0) ? -1e18 : arr2[cut2 - 1];
            ll r1 = (cut1 == n) ? 1e18 : arr1[cut1];
            ll r2 = (cut2 == m) ? 1e18 : arr2[cut2];
            if(l1 <= r2 and l2 <= r1){
                return max(l1, l2);
            }else if(l1 > r2){
                high = cut1 - 1;
            }else low = cut1 + 1;
        }
        return -1;
    }
};


// 7 11 15
// 1 10 10 25 40 54 79
// 15 24 27 32 33 39 48 68 82 88 90



// K = 5 (1-based)


// A = 2,3,6,7,9   n = 5
// B = 1,4,8,10  m = 4

// low = 0 , high = 7 


// => 1,2,3,4,  6  ,7,8,9,10

// all elements less than kth position will be small and others big

// less       high
// ....  kth  ....

// so we divide our sample space into 2 sections - one less than kth element and other greater than kth element.

// so left contains k elements and right contains n - k - 1 elements.

// so we try to binary search on the place where partition should be placed and check the validity of both the partitions.

// A = 2,3,6,7,9
// B = 1,4,8,10

// so we take some elements from set A and some elements from set B. if l1 < r2 and l2 < r1 so ans = max(l1 , l2);
