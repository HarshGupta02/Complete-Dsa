class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        string s1 = "", s2 = "";
        int ans = 0;
        if(x <= y){
            for(int i = 0; i < n ; i ++){
                if(s1.empty()) s1.push_back(s[i]);
                else if(s1.back() == 'b' and s[i] == 'a'){
                    ans += y;
                    s1.pop_back();
                }else s1.push_back(s[i]);
            }
            for(int i = 0; i < s1.size(); i ++){
                if(s2.empty()) s2.push_back(s1[i]);
                else if (s2.back() == 'a' and s1[i] == 'b'){
                    ans += x;
                    s2.pop_back();
                }else s2.push_back(s1[i]);
            }
        }else{
            for(int i = 0; i < n ; i ++){
                if(s1.empty()) s1.push_back(s[i]);
                else if(s1.back() == 'a' and s[i] == 'b'){
                    ans += x;
                    s1.pop_back();
                }else s1.push_back(s[i]);
            }
            for(int i = 0; i < s1.size(); i ++){
                if(s2.empty()) s2.push_back(s1[i]);
                else if (s2.back() == 'b' and s1[i] == 'a'){
                    ans += y;
                    s2.pop_back();
                }else s2.push_back(s1[i]);
            }
        }
        return ans;
    }
};

/*

if x <= y so choose the "ba" substring to remove because 

abab => x + x, y + x , so always preferred to choose second option as gives higher cost.

so removing one higher cost string is always beneficial.(greedy)


*/