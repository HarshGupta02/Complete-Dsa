/*
Given = 1. once an apartment is taken, it cannot be taken again
2. each person can take houses that lie in the range x - k <= maybe <= x + k.

since, we do not have to process the persons in the given order so we can sort
the person's array also.

if size < demand - k so no point of seeing greater demands so increase size.
if abs(size - demand) <= k, so once person, gets one apartment so move both i and 
j and increment ans by 1.
if size > demand + k so we move the persons demand as the gap decreases between
the size and demand.

*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll cnt = 0, i = 0, j = 0;
    while(i < n){
        while(j < m and b[j] < a[i] - k) j ++;
        if(abs(a[i] - b[j]) <= k) {
            cnt ++; i ++; j ++;
        }else i ++;
    }
    cout << cnt << "\n";
    return 0;
}