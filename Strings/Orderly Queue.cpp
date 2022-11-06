class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        // if k = 1 so we have to brute force to bring all the characters
        // to the start position and check the smallest string.
        if(k == 1){
            string ans = s;
            for(int i = 0; i < n; i ++){
                int x = s[0];
                s.erase(s.begin());
                s.push_back(x);
                if(s < ans) ans = s;
            }
            return ans;
        }else{
            /*
            if we see for k = 2, then we see that we can swap the first
            two characters as move the first char to last and then keep on
            removing the second char until we get back the first removed
            character
            
            then we can claim that we can swap any two pair of char which
            allows us to sort the string. we first keep the first char fixed
            and keep on moving the second char , then move the first char
            at last and then again keep on deleting the second char. in this
            way we can have all pairs of char at the first two position and 
            then swap them and make the string sorted.
            
            */
            sort(s.begin(), s.end());
            return s;
        }
    }
};