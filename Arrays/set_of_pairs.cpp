#include<bits/stdc++.h>
using namespace std;
int main(){
    set<pair<string, int>> st;
    st.insert({"hello", 2});
    st.insert({"leet", 3});
    // for(auto it : st) {
    //     cout << it.first << " " << it.second << endl;
    // }
    // st.erase({"hello", 2});
    auto it = st.erase(st.find({"hello", -1}));
    for(auto it : st) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}