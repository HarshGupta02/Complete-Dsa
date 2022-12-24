// METHOD 1:

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define nline "\n"
int main(){
    while(true){
        ll n;
        cin >> n;
        if(n == 0) break;
        vector<ll>a(n);
        for(int i = 0; i < n; i ++) cin >> a[i];
        int i = 0 , j = 0;
        ll ans = 0;
        while(i < n and j < n){
            if(a[i] == 0){
                i ++; continue;
            }
            if(a[j] == 0){
                j ++; continue;
            }
            assert(i >=0 and i < n and j >= 0 and j < n);

            if((i == j) or (a[i] >= 0 and a[j] >= 0) or (a[i] <= 0 and a[j] <= 0)){
                j ++; continue;
            }

            if(a[i] < 0 and a[j] > 0){
                if(abs(a[i]) < a[j]){
                    ans += (j - i) * abs(a[i]);
                    a[j] += a[i];
                    a[i] = 0; i ++ ; continue;
                }
                ans += (j - i) * abs(a[j]);   
                a[i] += a[j];
                a[j] = 0; j ++;
            }else{
                if(a[i] < abs(a[j])){
                    ans += (j - i) * abs(a[i]);
                    a[j] += a[i];
                    a[i] = 0; i ++ ; continue;
                }
                ans += (j - i) * abs(a[j]);
                a[i] += a[j];
                a[j] = 0; j ++;
            }
    }
    cout << ans << nline;
    }   
    return 0;
}

// METHOD 2:

/*
for a buyer,we take the closest seller and for the seller, we take the closest buyer.?? why
*/

class Solution{
  public:
  using ll = long long int;
  long long int wineSelling(vector<int>& a, int n){
      ll ans = 0;
      int b = -1, s = -1;
      while(b < n and a[b] < 0) b ++;
      while(s < n and a[s] > 0) s ++;
      
      while(b < n and s < n){
          while(b < n and a[b] <= 0) b ++;
          while(s < n and a[s] >= 0) s ++;
          ll x = min(a[b], -1 * a[s]);
          a[b] -= x;
          a[s] += x;
          ans += x * (abs(b - s));
      }
      return ans;
  }
};