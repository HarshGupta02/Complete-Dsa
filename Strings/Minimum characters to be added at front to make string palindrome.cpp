// METHOD 1: TIME = O(N) , SPACE = O(4 * N) ~~ O(N).

class Solution {
public:
    int minChar(string str){
        int n = str.size();
        string s = "@";
        for(int i = 0; i < n; i ++){
            s.push_back('#');
            s.push_back(str[i]);
        }
        s.push_back('#'); s.push_back('$');
        vector<int>lps(s.size() , 0);
        int center = 0 , right = 0;
        for(int i = 1; i < s.size(); i ++){
            int mirror = center - (i - center);
            if(i < right){
                lps[i] = min(lps[mirror] , right - i);
            }
            while(s[i + lps[i] + 1] == s[i - lps[i] - 1]){
                lps[i] ++;
            }
            if(i + lps[i] > right){
                center = i;
                right = i + lps[i];
            }
        }
        vector<int>v1,v2;
        for(int i = 0; i < s.size() ;i ++){
            if(s[i] == '@' or s[i] == '$') continue;
            if(s[i] == '#'){
                v2.push_back(lps[i]);
            }else{
                v1.push_back(lps[i]);
            }
        }
        int nax1 = -1;
        for(int i = 0; i < v1.size() ; i++){
            if(i == (v1[i] / 2)){
                nax1 = max(nax1, i);
            }
        }
        nax1 = 2 * nax1 + 1;
        int nax2 = -1;
        for(int i = 0; i < v2.size(); i++){
            if(i == (v2[i] / 2)){
                nax2 = max(nax2 , i);
            }
        }
        nax2 = 2 * nax2;
        return n - max(nax1, nax2);
    }
};

// METHOD 2: 

/*
here we check if first and last characters are same or not. if same if we move to 
next closer pair of elements and then if they are not equal so the whole string 
cannot become a palindrome so the j1 th character is added at front(virtually) and 
then we know that the first and last character are the same so we do j1 --.
*/

class Solution {
public:
    int minChar(string str){
        int n = str.size();
        int i = 0, j = n - 1, j1 = n - 1;
        int cnt = 0;
        while(i < j){
            if(str[i] == str[j]){
                i ++; j --; continue;
            }
            cnt ++;
            i = 0; j1 --;
            j = j1;
        }
        return cnt;
    }
};