#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int nax = 5;
int front = -1, rear = -1;
int a[nax];

void push(int x){
    if(front == -1 and rear == -1){
        front ++; rear ++;
        a[rear] = x; return;
    }
    if((rear + 1) % nax == front){
        cout << "circular queue overflow , cannot insert elements" << endl;
        exit(0);
    }
    rear = (rear + 1) % nax; 
    a[rear] = x;
}

int pop(){
    if(front == -1){
        cout << "Circular queue underflow , cannot delete elements" << endl;
        exit(0);
    }
    int rmv = a[front];
    a[front] = -1;
    if(front == rear){
        front = -1;
        rear = -1;
    }
    front = (front + 1) % nax;
    return rmv;
}

void print_queue(){
    if(front <= rear){
        for(int i = front; i <= rear ; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = front; i < nax ; i ++){
        cout << a[i] << " ";
    }
    for(int i = 0; i <= rear ; i ++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(){
    while(true){
        int x , n;
        cin >> x;
        if(x == -1) break;
        if(x == 1){
            cin >> n; push(n);
        }
        else if(x == 2) pop();
        print_queue();
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