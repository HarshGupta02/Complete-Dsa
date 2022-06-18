class Solution {
public:
    int maxSubStr(string str){
        int n = str.size();
        int one_cnt = 0,zero_cnt = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '1') one_cnt ++; 
            else zero_cnt ++;
        }
        if(one_cnt != zero_cnt) return -1;
        /// moore's vooting algo
        int best_cnt = 0 , best_candidate;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(best_cnt == 0){
                ans ++;
                best_cnt ++; best_candidate = str[i]; continue;
            }
            if(str[i] != best_candidate){
                best_cnt --;
            }else{
                best_cnt ++;
            }
        }
        return ans;
    }
};