class Solution{
public:
    using ll = long long int;
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());
        ll ans = 0 ;
        for(int i =0 ; i < N ; i ++){
            ans += abs(A[i] - B[i]);
        }
        return ans;
    }
};