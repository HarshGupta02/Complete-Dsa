/*
we see that if 2 arrays are sorted then if we they have some element 
common and we start pointers from 0 and move that pointer which is smaller
then our i and j will start moving together from the intersection point.

*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
#define nline endl

int main(){
    while(true){
        ll n , m;
        cin >> n;
        if(n == 0) break;
        vector<ll>x1(n);
        for(int i = 0; i < n ; i ++) cin >> x1[i];
        cin >> m;
        vector<ll>x2(m);
        for(int i = 0; i < m ; i ++) cin >> x2[i];
        ll s1 = 0 , s2 = 0;
        int i = 0 , j = 0;
        ll ans = 0;
        while(i < n and j < m){
            if(x1[i] == x2[j]){
                ans += max(s1 , s2) + x1[i];
                s1 = 0; s2 = 0; i++; j ++;
            }else if(x1[i] < x2[j]){
                s1 += x1[i]; i ++;
            }else{
                s2 += x2[j]; j ++;
            }
        }
        while(i < n){
            s1 += x1[i]; i ++;
        }
        while(j < m){
            s2 += x2[j]; j ++;
        }
        ans += max(s1,s2);
        cout << ans << nline;
    }
    return 0;
}