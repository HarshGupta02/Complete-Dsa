class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]); continue;
            }
            int tp = st.top();
            if((s[i] == ')' and tp == '(') or (s[i] == '}' and tp == '{') or ((s[i] == ']' and tp == '['))){
                st.pop(); continue;
            }
            st.push(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }
};