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