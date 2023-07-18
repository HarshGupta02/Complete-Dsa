/*
so we see that first of all, the indices of characters are more important that the
characters itself. so we maintain two stacks of open and star. if current char is
open so push index in open, if star so push index in star.
if current character is closed so first check if open is not empty. if not empty,
then he will match with current so pop from open. if empty so check star, if not
empty so can become open and will match. if both empty so return false.

so now all closed are balanced. so now we balance open indices and then we check 
the top open char of open stack and if open.top() < star.top() so star can become
close and it will match else return false. 

now if open stack is empty() so return true as if some elements left in star stack,
will act as blank spaces.

*/

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> open, star;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else {
                if(open.empty() and star.empty()) return false;
                if(!open.empty()) open.pop();
                else star.pop();
            }
        }
        while(!open.empty()) {
            if(star.empty() or open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return true;
    }
};