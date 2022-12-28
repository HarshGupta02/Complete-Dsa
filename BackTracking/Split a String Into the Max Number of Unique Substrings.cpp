class Solution {
public:
    
    using ll = long long int;
    
    int f(int i, string &s, unordered_set<string> &st, string temp){
        if(i == s.size()) return 0;
        temp += s[i];
        ll ans1 = INT_MIN, ans2 = INT_MIN;
        if(st.find(temp) == st.end()){
            st.insert(temp);
            ans1 = 1 + f(i + 1, s, st, "");
            st.erase(temp);
        }
        ans2 = f(i + 1, s, st, temp);
        return max(ans1, ans2);
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return f(0, s, st, "");
    }
};