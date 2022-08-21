/*
TIME = O(N * (N - M)), SPACE = O(N) IF NOT CONSIDER THE SIZE OF RETURN ARRAY.

here we use the fact that after each replacement of the string s, we have a substring 
stamp in s after each operation. so we use this fact and go from target to ????...

now each ? in an intermediate step will be considered that it can be replaced with any 
character as happened in reverse order.

but if we apply reverse operation on an index so we mark it as true and convert it to all ?..
and we cannot apply the opertion again on this index as would lead to TLE as each stamp will
replace itself with all ? mark's and other characters will not be able to change themselves.

*/

class Solution {
public:
    
    bool canReplace(string target, int i, string stamp){
        for(int j = 0; j < stamp.size(); j ++){
            if(target[i + j] == '?' or stamp[j] == target[i + j]) continue;
            return false;
        }
        return true;
    }
    
    int replace(string &target, int i, string stamp, int &count){
        for(int j = 0; j < stamp.size(); j ++){
            if(target[i + j] == '?') continue;
            target[i + j] = '?';
            count ++;
        }
        return count;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        int s_sz = stamp.size(), t_sz = target.size();
        vector<bool>visited(t_sz, false);
        vector<int>ans;
        while(count != t_sz){
            bool didChange = false;
            for(int i = 0; i <= t_sz - s_sz; i ++){
                if(!visited[i] and canReplace(target, i, stamp)){
                    didChange = true;
                    count = replace(target, i, stamp, count);
                    visited[i] = true;
                    ans.push_back(i);
                    if(count >= t_sz) break;
                }
            }
            if(!didChange) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*

?????
abc??
ababc

???????
???abca
abcabca
aabcaca

10 * target.length === N * logN approach or less

as 1000 * log 1000 ~ 1000 * 10 turns or operations

1. target's first character and stamp's first character should be same and
same goes for the last character of both stamp and target.

2. we have to perform atleast 2 operations. place stamp on starting and at
the end. (necessary).

???????
=> abca???
=> abcabca (inserted stamp at first and last character).
=> aabcaca

?????
=> abc??
=> ababc

?????
=> abc??
=> ababc

=> since after each operation, we are placing stamp at an index so we can
go back and replace occurences of stamp in target to -> ???.




*/