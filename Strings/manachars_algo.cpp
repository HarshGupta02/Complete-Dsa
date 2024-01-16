#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    string t = "@";
    for(int i = 0; i < n; i ++) {
        t.push_back('#');
        t.push_back(s[i]);
    }
    t.push_back('#'); t.push_back('$');
    int m = t.size();
    int center = 0, right = 0;
    vector<int> lps(m, 0);
    for(int i = 2; i < m - 1; i ++) {
        int mirror = center - (i - center);
        if(i < right) lps[i] = min(lps[mirror], right - i);
        while(t[i + lps[i] + 1] == t[i - lps[i] - 1]) lps[i] ++;
        if(i + lps[i] > right) {
            center = i;
            right = i + lps[i];
        }
    }
    int len = 0, idx = -1;
    for(int i = 0; i < m; i ++) {
        if(lps[i] > len) {
            len = lps[i];
            idx = i;
        }
    }
    int start = ((idx - lps[idx] + 1) - 2)/2;
    cout << s.substr(start, lps[idx]);
    return 0;
}