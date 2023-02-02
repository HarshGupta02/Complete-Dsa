/*
we first sort the array. then if first element is not 1 so ans = 1.
else we know that the min sum possible is 1 and let's say, we use a hypothesis that 
at index i, we can have all subset sum from 1 to k on i - 1 index.

if a[i] > k + 1 so the min sum possible by including the a[i]th element will always be 
greater than k + 1, so ans = k + 1.

if a[i] <= k + 1 so k + 1 - a[i] >= 0 and k + 1 - a[i] <= k + 1 so all sum's can be created
from 1 to k + 1 by including the a[i]th element.

*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll curr = 0;
    for(int i = 0; i < n; i ++){
        // till i - 1 index, we can create all subsset sum from 1 to curr.
        if(curr + 1 < a[i]) break;
        curr += a[i];
    }
    cout << curr + 1 << "\n";
    return 0;
}