class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        int best_votes = 0, best_candidate;
        for(int i = 0; i < size; i ++){
            if(best_votes == 0){
                best_candidate = a[i];
            }
            if(a[i] == best_candidate) best_votes ++;
            else best_votes --;
        }
        int is_it = 0;
        for(int i = 0 ; i < size; i ++){
            if(a[i] == best_candidate) is_it ++;
        }
        if(is_it > size / 2) return best_candidate;
        return -1;
    }
};