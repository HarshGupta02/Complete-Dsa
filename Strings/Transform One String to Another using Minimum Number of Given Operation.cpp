/// TIME = O(N) , SPACE = O(256) ~~ O(1).

/*

here we try to make both the string equal by making each character equal , and in doing so we start this from back
and not from front because if we encounter two different characters then we have to send it to the front but our
attempt to make the prefix char same might being distorted so we start to make characters equal from the back so 
that if we find two different characters then we will send it to the front and our suffix will not be affected.

so either i and j both finish at 0 or either i will arrive at 0 earlier than j and the string before j is the 
string that would have been formed by moving the rejected characters in front of A string.

*/

class Solution{
    public:
    int transfigure (string A, string B)
    {
        int n1 = A.size() , n2 = B.size();
        vector<int>v(256 , 0);
        for(int i = 0 ; i < n1 ; i ++){
            v[A[i]] ++;
        }
        for(int i = 0; i < n2 ; i ++){
            v[B[i]] --;
        }
        for(int i = 0; i < 256; i ++){
            if(v[i] != 0){
                return -1;
            }
        }
        int i = n1 - 1 , j = n2 - 1;
        int ans = 0;
        while(i >= 0){
            while(i >= 0 and A[i] != B[j]){
                i --;
                ans ++;
            }
            if(i >= 0){
                i --; j --;
            }
        }
        return ans;
    }
};