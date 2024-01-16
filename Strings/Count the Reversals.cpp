/// TIME = O(N) , SPACE = O(N)


class Solutions{
    public:
    int min_op(char c1 , char c2){
        if(c1 == '{' and c2 == '{') return 1;
        if(c1 == '{' and c2 == '}') return 2;
        if(c1 == '}' and c2 == '}') return 1;
        return 0;
    }

    int countRev (string s)
    {
        int n = s.size();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            int tp = st.top();
            if(tp == '{' and s[i] == '}'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.size() % 2 == 1) return -1;
        int ans = 0;
        while(!st.empty()){
            int tp1 = st.top();
            st.pop();
            int tp2 = st.top();
            st.pop();
            ans += min_op(tp1 , tp2);
        }
        return ans;
    }
};
