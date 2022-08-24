/*

here we see that we need to have 4 numbers each with size >= 1 and size <= 3 so a,b,c,d
does that only. then we first find the string , convert to integer and then again 
convert to string so that the leading zeros are removed and if there would have 
existed leading zeros then they would have been removed and the lenght of the final 
string would be less tha the original string.

*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string>ans;
        for(int a = 1; a <= 3; a ++){
            for(int b = 1; b <= 3; b ++){
                for(int c = 1; c <= 3; c ++){
                    for(int d = 1; d <= 3; d ++){
                        if(a + b + c + d != n) continue;
                        string s1 = s.substr(0, a), s2 = s.substr(a, b), s3 = s.substr(a + b, c), s4 = s.substr(a + b + c, d);
                        int n1 = stoi(s1), n2 = stoi(s2), n3 = stoi(s3), n4 = stoi(s4);
                        if(n1 <= 255 and n2 <= 255 and n3 <= 255 and n4 <= 255){
                            string res = to_string(n1) + "." + to_string(n2) + "." + to_string(n3) + "." + to_string(n4);
                            if(res.size() == n + 3) ans.push_back(res);
                        }
                        
                    }
                }
            }
        }
        return ans;
    }
};