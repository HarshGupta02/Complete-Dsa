class Solution {
  public:
    string longestPalin (string S) {
        int n = S.size();
        string str = "@";
        for(int i = 0 ; i < n ; i ++){
            str.push_back('#');
            str.push_back(S[i]);
        }
        str.push_back('#'); str.push_back('$');
        int n1 = str.size();
        vector<int>lps(n1,0);
        int center = 0 , right = 0;
        for(int i = 1; i < n1 ; i ++){
            int mirror = center - (i - center);
            if(i < right) lps[i] = min(lps[mirror] , right - i);
            while(str[i + lps[i] + 1] == str[i - lps[i] - 1]) lps[i] ++;
            if(right < lps[i] + center){
                right = lps[i] + center;
                center = i;
            }
        }
        int best_idx , best_len = 0;
        for(int i = 0; i < n1; i ++){
            if(lps[i] > best_len){
                best_len = lps[i];
                best_idx = i;
            }
        }
        if(str[best_idx] != '#'){
            int start = ((best_idx - best_len) + (best_len % 2))/2 - 1;
            return S.substr(start , (best_len % 2) ? best_len : best_len + 1);
        }
        int start = ((best_idx - best_len) + !(best_len % 2))/2 - 1;
        return S.substr(start , !(best_len % 2) ? best_len : best_len + 1);
    }
};