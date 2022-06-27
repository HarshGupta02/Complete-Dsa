class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.rbegin() , X.rend()); sort(Y.rbegin() , Y.rend());
        /// X = VERTICAL , Y = HORIZONTAL
        int h_pieces = 1 , v_pieces = 1;
        int i = 0 , j = 0;
        int total = 0;
        while(i < M and j < N){
            if(X[i] >= Y[j]){
                total += X[i] * h_pieces;
                v_pieces ++; i ++;
            }else{
                total += Y[j] * v_pieces;
                h_pieces ++; j ++;
            }
        }
        while(i < M){
            total += X[i] * h_pieces;
            v_pieces ++; i ++;
        }
        while(j < N){
            total += Y[j] * v_pieces;
            h_pieces ++; j ++;
        }
        return total;
    }
};