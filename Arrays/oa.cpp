#include<bits/stdc++.h>
using namespace std;

int main(){
    int h;
    cin >> h;
    int n = (1 << h) - 1;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int target;
    cin >> target;
    int curr = 0;
    string ans = "";
    while(a[curr] != target) {
        int left = 2*curr + 1, right = 2*curr + 2;
        
    }
    return 0;
}