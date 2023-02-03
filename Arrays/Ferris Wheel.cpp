/*
so since we can have max of 2 people, so we first sort the weights. then if
we greedily pick up 2 members from starting so it will not always be correct
because after some time only larger weights people will be present so all 
would need an individual gondolas.

so we use 2 pointer approach and then we try to assign the bigger weight person
to the smallest possible weight and if total weight is <= x so both are part
of a ferry else the bigger weight person would need a separate ferry.

if i == j so there will always be one person in the ferry but if i != j so it
is ensured that all are part of one or the other ferry.

*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
#define debug(x) cout<< #x <<" = "; _print(x); cout <<endl

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for(int i = 0; i < n; i ++) cin >> w[i];
    sort(w.begin(), w.end());
    int i = 0, j = n - 1;
    ll gondo = 0;
    while(i <= j){
        ll curr = w[i] + w[j];
        if(curr <= x) {
            i ++; j --; gondo ++;
        }else {
            j --; gondo ++;
        }
    }
    cout << gondo << "\n";
    return 0;
}