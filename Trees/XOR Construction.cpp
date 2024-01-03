#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

struct Node {
    Node* links[2];
    Node() {
        links[0] = nullptr; links[1] = nullptr;
    }
    bool isContainsKey(int bit) {
        return links[bit] != nullptr;
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit) {
        links[bit] = new Node();
    }
};

class Trie{
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int x) {
        Node* curr = root;
        for(int i = 31; i >= 0; i --) {
            int bit = (x & (1 << i)) ? 1 : 0;
            if(curr -> isContainsKey(bit) == false)
                curr -> put(bit);
            curr = curr -> get(bit);
        }
    }
    int query(int x) {
        Node* curr = root;
        int mask = 0;
        for(int i = 31; i >= 0; i --) {
            int curr_bit = (x & (1 << i)) ? 1 : 0;
            int needed_bit = 1 - curr_bit;
            if(curr -> isContainsKey(needed_bit)) {
                mask |= (1 << i);
                curr = curr -> get(needed_bit);
            }else curr = curr -> get(curr_bit);
        }
        return mask;
    }
};

void solve(){
    int n;
    cin >> n;
    int a[n - 1];
    for(int i = 0; i < n - 1; i ++) cin >> a[i];
    int xorr = 0;
    vector<int> prefix;
    prefix.push_back(xorr);
    for(int i = 0; i < n - 1; i ++) {
        xorr = xorr ^ a[i];
        prefix.push_back(xorr);
    }
    Trie trie;
    for(int i = 0; i < n; i ++) 
        trie.insert(prefix[i]);
    int can = -1;
    for(int first = 0; first <= n - 1; first ++) {
        int maxi = trie.query(first);
        if(maxi == n - 1) {
            can = first;
            break;
        }
    }
    assert(can != -1);
    cout << can << " ";
    for(int i = 0; i < n - 1; i ++) {
        can = can ^ a[i];
        cout << can << " ";
    }
    cout << "\n";
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