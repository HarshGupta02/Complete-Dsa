/// HERE WE USED THE CONCEPT THAT WE BINARY SEARCH ON THE MAX NUMBER OF PAGES THAT CAN BE 
/// ASSSIGNED TO EACH STUDENT . WE ITERATE FROM LEFT AND KEEP ON ASSIGNING BOOKS TO A STUDENT
/// UNTIL HE REACHES THE (MID) MAX NUMBER OF PAGES.

//// IF COUNT OF SUCH STUDENTS ARE LESS THAN OR EQUAL TO M , THEN IT CAN BE ONE OF THE ANSWERS
// BECAUSE IF COUNT < M , THEN WE CAN EASILY GIVE MORE BOOKS TO MORE STUDENTS WITHOUT
// CONSIDERING THE UPPER LIMIT.


class Solution 
{
    public:
    using ll = long long int;
    bool helper(int A[] , int N , int M ,ll mid){
        int cnt = 1 , curr_sum = 0;
        for(int i = 0; i < N ; i ++){
            if(A[i] > mid) return false;
            if(curr_sum + A[i] > mid){
                curr_sum = A[i];
                cnt ++;
            }else{
                curr_sum += A[i];
            }
        }
        if(cnt > M) return false;
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        ll sum = 0;
        for(int i = 0 ; i < N; i ++) sum += A[i];
        ll low = 0 ,high = sum;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(A, N , M , mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};