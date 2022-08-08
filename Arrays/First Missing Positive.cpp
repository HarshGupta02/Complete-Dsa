/*
if an array of size n so the ans will be always in the range 1 .... n + 1.
so we try to bring the elements of the array equal to the their value's index.
so the first failed index which could not do it , is the answer.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i ++){
            a[i] = (long long int)a[i] - 1;
            // used long long int to be in range of long int as here only int
            // was used.
        }
        for(int i = 0; i < n; i ++){
            while(a[i] >= 0 and a[i] < n and a[i] != i){
                if(a[i] != a[a[i]]) swap(a[i], a[a[i]]);
                else break;
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i ++){
            if(a[i] != i){
                ans = i + 1; break;
            }
        }
        return ans == -1 ? n + 1 : ans;
    }
};