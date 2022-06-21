class Solution{
  public:
    using ll = long long int;
    ll ans = 0;
    
    void Merging(ll arr[] , ll low , ll mid , ll high){
        ll n1 = (mid - low) + 1;
        ll n2 = (high - (mid + 1)) + 1;
        vector<ll>a1(n1) , a2(n2);
        ll i = 0, j = 0, k = low;
        while(i < n1){
            a1[i] = arr[k];
            i ++; k ++;
        }
        while(j < n2){
            a2[j] = arr[k];
            j ++; k ++;
        }
        i = 0 , j = 0 , k = low;
        while(i < n1 and j < n2){
            if(a1[i] <= a2[j]){
                arr[k] = a1[i];
                i ++; k ++; continue;
            }
            if(a1[i] > a2[j]){
                ans += (n1 - i);
                arr[k] = a2[j];
                j ++; k ++; continue;
            }
        }
        while(i < n1){
            arr[k] = a1[i];
            i ++; k ++;
        }
        while(j < n2){
            arr[k] = a2[j];
            j ++; k ++;
        }
    }
    
    void MergeSort(ll arr[] , ll low , ll high){
        if(low >= high) return;
        ll mid = low + (high - low)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merging(arr,low,mid,high);
    }
  
    long long int inversionCount(long long arr[], long long N)
    {
        MergeSort(arr , 0 , N - 1);
        return ans;
    }

};