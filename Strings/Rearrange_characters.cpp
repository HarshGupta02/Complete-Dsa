// TIME = O(N) + O(N LOG N) ~~ O(N LOG N) , SPACE = O(26) ~~ O(1)

/* here we can choose any character to place but we will choose the character with the max frequency
because if don't choose it then it will be used at the end and will have more changes of adjacent
characters being equal.

now we place the same characters alternatively either starting from index 0 or from index 1 but we
will start from index 0 because in case of odd lenght strings , we will have more slots for the max
character == (n + 1)/2;

now since we don't want two adjacent characters to be equal so we will try to place characters in
pairs and choose the 2 characters with the max frequency and decrease their count by 1 and this will
ensure that the all the characters decrease by the same amount and the chances of collision becomes
very less.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char,int>mp;
    for(int i = 0; i < n; i ++){ /// takes O(N)
        mp[s[i]] ++;
    }
    priority_queue<pair<int,char>>pq; //// takes O(N logN)
    for(char ch = 'a'; ch <= 'z'; ch++){
        if(mp[ch] > 0) pq.push({mp[ch] , ch});
        if(mp[ch] > (n + 1)/2){
            cout << 0 << nline;
            return;
        }
    }
    string res = "";
    while(pq.size() >= 2){ /// can have max of 26 letters.
    /// push takes O(N LOG N) in worst case.
        char ch1 = pq.top().second; int f1 = pq.top().first; pq.pop();
        char ch2 = pq.top().second; int f2 = pq.top().first; pq.pop();
        res += ch1; res += ch2;
        if(f1 - 1 > 0) pq.push({f1 - 1 , ch1});
        if(f2 - 1 > 0) pq.push({f2 - 1 , ch2});
    }
    if(!pq.empty()) res += pq.top().second;
    cout << 1 << nline;
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}


/*

TIME = O(26 * N) ~~ O(N) , SPACE = O(26 + N) ~~ O(N).

here we used the concept that the freq of each character cannot exceed (n + 1)/2; so we can assure that
two characters will never be adjacent to each other.

here the character with the max frequency is placed at the even positions(0 based indexing) and then 
the remaining characters are placed first at the remaining even positions and then at the odd positions.
this ensures that the same characters will always alternate.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int>freq;

void solve(){
    string s;
    cin >> s;
    freq.resize(26,0);
    int n = s.size();
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a'] ++;
    }
    int max_times = 0;
    char ch;
    for(int i = 0; i < 26; i++){
        if(freq[i] > max_times){
            max_times = freq[i];
            ch = 'a' + i;
        }
    }
    if(max_times > (n + 1)/2){
        cout << "" << nline;
        return;
    }
    int idx = 0;
    string res(n ,' ');
    while(max_times --){
        res[idx] = ch;
        idx += 2;
    }
    freq[ch] = 0;
    for(int i = 0; i < 26; i ++){
        while(freq[i] --){
            idx = (idx >= n) ? 1 : idx;
            res[idx] = 'a' + i;
            idx += 2;
        }
    }
    cout << res << nline;
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}