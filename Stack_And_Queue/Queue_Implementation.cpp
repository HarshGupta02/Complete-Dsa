#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MAXN = 5;
int front = -1 , back = -1;

int stk[MAXN];

void push(int x){
    if(back == MAXN){
        cout << "Queue overflow , cannot insert elements" << endl;
        exit(0);
    }
    if(front == -1 and back == -1){
        front ++;
    }
    back ++;
    stk[back] = x;
}

int pop(){
    if(front == -1 and back == -1){
        cout << "Queue underflow , cannot delete elements" << endl;
        exit(0);
    }
    int removed_element = stk[front];
    front ++;
    return removed_element;
}

int start(){
    return stk[front];
}

int rear(){
    return stk[back];
}

bool isEmpty(){
    return (front == -1 and back == -1) ? true : false;
}

void print_queue(){
    for(int i = front ; i <= back ; i ++){
        cout << stk[i] << " ";
    }
    cout << endl;
}

void solve(){
    // push(10);
    // print_queue();
    // push(4);
    // print_queue();
    // push(12);
    // print_queue();
    // int x = pop();
    // print_queue();
    // push(20);
    // print_queue();
    // push(30);
    // print_queue();
    // push(40);
    // print_queue();
    // push(50);
    // print_queue();
    push(10);
    int x = pop();
    x = pop();
    print_queue();
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