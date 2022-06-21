class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        bitset<100005>bst; /// 0.26/2.7
        // unordered_map<int,int>bst; 0.6/2.7
        int maxi = -1;
        for(int i = 0; i < N;i++){
            bst[arr[i]] = 1;
            maxi = max(maxi , arr[i]);
        }
        int glob_max = 1 , curr = 0;
        for(int i = 0;i <= maxi;i++){
            if(bst[i] == 1){
                curr ++;
                glob_max = max(glob_max , curr);
            }else{
                curr = 0;
            }
        }
        return glob_max;
    }
};