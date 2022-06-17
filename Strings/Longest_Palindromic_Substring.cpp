// O(N ^ 2)


class Solution {
public:
    
    int best_len = 0, best_start, best_end;
    
    void optimal(int a,int b){
        best_len = a;
        best_start = b;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        for(int mid = 0; mid < n; mid ++){
            for(int x = 0 ; mid - x >= 0 and mid + x < n; x ++){
                if(s[mid - x] != s[mid + x]) break;
                int len = 2 * x + 1;
                if(len > best_len){
                    optimal(len,mid - x);
                }
            }
        }
        for(int mid = 0; mid < n - 1; mid ++){
            for(int x = 1; mid - x + 1 >= 0 and mid + x < n; x ++){
                if(s[mid - x + 1] != s[mid + x]) break;
                int len = 2 * x;
                if(len > best_len){
                    optimal(len, mid - x + 1);
                }
            }
        }
        return s.substr(best_start, best_len);
    }
};

// O(N ^ 2) - Manacher's Algorithm (Brute)


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string st = "";
        st.push_back('@');
        for(int i = 0; i < n; i ++){
            st.push_back('#');
            st.push_back(s[i]);
        }
        st.push_back('#'); st.push_back('$');
        vector<int>lps(st.size() , 0);
        /// here lps[i] = stores the max number of jumps(not inclduing itself) we can make on either side of the 
        /// current element such that the string enclosed within the right and the left bound
        /// is a palindrome. /// 1-length string is already a palindrome.
        for(int i = 1; i < st.size() - 1; i ++){
            while(st[i + lps[i] + 1] == st[i - lps[i] - 1]){
                lps[i] ++;
            }
        }
        int best_len = 0, best_idx;
        for(int i = 0; i < st.size(); i ++){
            if(lps[i] > best_len){
                best_len = lps[i];
                best_idx = i;
            }
        }
        // cout << "lenght of the longest palindromic substring is " << best_len << endl;
        if(st[best_idx] != '#'){
            int start = ((best_idx - best_len) + (best_len % 2))/2 - 1;
            return s.substr(start,(best_len % 2 == 1 ? best_len : best_len + 1));
        }
        int start = ((best_idx - best_len) + !(best_len % 2))/2 - 1;
        return s.substr(start,(best_len % 2 == 0 ? best_len : best_len + 1));
    }
};

/// O(N) - Manchar's Algo Optimised


class Solution {
public:
    string longestPalindrome(string s) {
        /// Manachar's Algo
        int n = s.size();
        string st = "";
        st.push_back('@');
        for(int i = 0; i < n; i++){
            st.push_back('#');
            st.push_back(s[i]);
        }
        st.push_back('#'); st.push_back('$');
        vector<int>lps(st.size(), 0);
        int center = 0, right = 0;
        ///      center - gap .. mirror... center ..i... (center + gap) = right
        for(int i = 1; i < st.size() - 1; i++){
            int mirror = center - (i - center);
            if(i < right){
                lps[i] = min(lps[mirror] , right - i);
            }
            while(st[i + 1 + lps[i]] == st[i - 1 -lps[i]]){
                lps[i] ++;
            }
            if(i + lps[i] > right){
                center = i;
                right = i + lps[i];
            }
        }
        int best_len = 0, best_idx;
        for(int i = 0; i < st.size(); i++){
            if(lps[i] > best_len){
                best_len = lps[i];
                best_idx = i;
            }
        }
        if(st[best_idx] != '#'){
            int start = ((best_idx - best_len) + (best_len % 2))/2 - 1;
            return s.substr(start, (best_len % 2) ? best_len : best_len + 1);
        }
        int start = ((best_idx - best_len) + !(best_len % 2))/2 - 1;
        return s.substr(start, !(best_len % 2) ? best_len : best_len + 1);
    }
};



