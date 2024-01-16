#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int r = 3, c = 4;
    // int *ptr = (int *)malloc((r * c) * sizeof(int));
    // for(int i = 0; i < r * c; i ++) ptr[i] = i + 1;
    // for(int i = 0; i < r; i ++) {
    //     for(int j = 0; j < c; j ++) {
    //         cout << ptr[i * c + j] << " ";
    //     }
    //     cout << endl;
    // }
    // free(ptr);

    int *arr[r];
    for(int i = 0; i < r; i ++) {
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    int count = 0;
    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            arr[i][j] = count ++;
        }
    }
    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}