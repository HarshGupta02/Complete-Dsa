#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int top = -1;
const int MAXN = 1e5 + 5;
int stk[MAXN];
int middle;

void push(int x){
    if(top == MAXN - 1){
        cout << "overflow , elements cannot be inserted" << endl;
        exit(0);
    }
    top ++;
    stk[top] = x;
    middle = (top % 2 == 0) ? stk[top/2] : stk[(top + 1)/2];
}

int pop(){
    if(top == -1){
        cout << "Underflow , elements cannot be deleted as already empty" << endl;
        exit(0);
    }
    int removed_element = stk[top];
    top --;
    return removed_element;
}

int peek(){
    return stk[top];
}

bool isEmpty(){
    return (top == -1) ? true : false;
}

int find_middle(){
    return middle;
}

void print_stack(){
    assert(top > -1);
    int temp = top;
    while(temp != -1){
        cout << stk[temp] << " ";
        temp --;
    }
    cout << endl;
}

void solve(){
    push(10);
    push(3);
    push(12);
    push(24);
    push(123);
    cout << find_middle() << endl;
    push(13);
    cout << find_middle() << endl;
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