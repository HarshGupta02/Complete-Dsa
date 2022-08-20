class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>last(26);
        vector<bool>seen(26, false);
        string ans = "";
        for(int i = 0; i < n ; i ++) last[s[i] - 'a'] = i;
        for(int i = 0; i < n ; i ++){
            if(seen[s[i] - 'a']) continue;
            while(ans.back() > s[i] and last[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            seen[s[i] - 'a'] = true;
            ans.push_back(s[i]);
        }
        return ans;
    }
};

/*
cbacdcbc

char and their index of occurence

a -> 3
b -> 2, 7
c -> 1,4,6,8
d -> 5

=> c
=> b
=> a
=> acd
=> acdb

a -> 1
b -> 2
c -> 4
d -> 1

acdb

*/