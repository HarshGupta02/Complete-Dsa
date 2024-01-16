#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

struct Node{
    Node* links[26];
    int end_with, occ;

    Node() {
        for(int i = 0; i < 26; i ++) links[i] = nullptr;
        end_with = 0;
        occ = 0;
    }
    bool isContainsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch) {
        links[ch - 'a'] = new Node();
    }
};

class Trie{
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        int n = s.size();
        Node* curr = root;
        for(int i = n - 1; i >= 0; i --) {
            char ch = s[i];
            if(curr -> isContainsKey(ch) == false)
                curr -> put(ch);
            curr = curr -> get(ch);
            curr -> occ ++;
        }
        curr -> end_with ++;
    }
    int query(string s) {
        int n = s.size(), res = 0;
        Node* curr = root;
        for(int i = 0; i < n; i ++) {
            char ch = s[i];
            if(curr -> isContainsKey(ch) == true) {
                curr = curr -> get(ch);
                res += (i + 1) * (curr -> end_with);
            }else break;
        }
        res += ((curr -> occ - 1) * n);
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    int total = 0;
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
        total += (int)v[i].size();
    }
    int lcp = 0;
    Trie trie;
    for(int i = 0; i < n; i ++) {
        trie.insert(v[i]);
    }
    for(int i = 0; i < n; i ++) {
        int curr = trie.query(v[i]);
        lcp += curr;
    }
    cout << 2*n*total - 2*lcp << "\n";
}

signed main() {
    fast_cin();
    int test_cases = 1;
    // cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}