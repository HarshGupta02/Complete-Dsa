/*
so here we needed to find the number of substrings with #1 > #0 so first of all, we
set all 0's to -1. then we find the prefix sum of the modified array. if p[i] > 0 so
it is for sure that this prefix has more 1's than 0's (because if p[i] < 0 so more
0's , if p[i] = 0 so equal number of 0's and 1's, if p[i] > 0 so more number of 1's).

now for the modified prefix array, we count number of pairs with p[i] < p[j] (count 
inversions) as these pairs gives the number of subarrays[i + 1......j] such that they
have more 1's than 0. (also since p[j] > p[i] so some positive quantity must be 
added to p[i] to make it p[j] and this postive quantity ensures that there are more
1's than 0's in that subarray).

but the count of these inversions does not include the subrarrys which are prefix of 
the modified prefix array (as all inversions will count subarrays from [i + 1...j]
so the subarrays with first element never gets considered) so we needed to include 
them separately to our ans.

*/

class Solution{
public:
  using ll = long long int;
  ll inversions = 0;
  
  void mergee(vector<ll> &v, int low, int mid, int high){
      ll n1 = (mid - low) + 1, n2 = high - mid;
      vector<ll> a(n1), b(n2);
      int i = 0, j = 0, k = low;
      while(i < n1) a[i ++] = v[k ++];
      while(j < n2) b[j ++] = v[k ++];
      i = 0, j = 0, k = low;
      while(i < n1 and j < n2){
          if(a[i] <= b[j]) v[k ++] = a[i ++];
          else {
              inversions += (n1 - i);
              v[k ++] = b[j ++];
          }
       }
       while(i < n1) v[k ++] = a[i ++];
       while(j < n2) v[k ++] = b[j ++];
  }
  
  void mergeSort(vector<ll> &v, int low, int high){
      if(low >= high) return;
      int mid = low + (high - low)/2;
      mergeSort(v, low, mid);
      mergeSort(v, mid + 1, high);
      mergee(v, low, mid, high);
  }
  
  long long countSubstring(string s){
      int n = s.size();
      vector<ll> v(n);
      ll ans = 0;
      for(int i = 0; i < n; i ++){
          if(s[i] == '1') v[i] = 1;
          else v[i] = -1;
          if(i > 0) v[i] += v[i - 1];
          if(v[i] > 0) ans ++;
      }
      reverse(v.begin(), v.end());
      mergeSort(v, 0, n - 1);
      ans += inversions;
      return ans;
  }
};