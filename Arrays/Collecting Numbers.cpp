/*
since we have to select numbers from left to right as max as possible so never increment round by
one when going right so whenever there is a left edge so increment the round by one.

since on going right, we ensure that the index and also the value wil be greater than the index 
on the left. so we converted the array to indexes to ensure that atleast the indexes are sorted 
in increasing order and we just need to check the value.

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
    vector<ll> poss(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        a[i] --;
        poss[a[i]] = i;
    }
    ll rounds = 1;
    for(int i = 1; i < n; i ++){
        if(poss[i] < poss[i - 1]) rounds ++;
    }
    cout << rounds << "\n";
    return 0;
}