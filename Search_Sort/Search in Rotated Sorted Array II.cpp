/*

here if a[mid] = a[low] = a[high] so we don't know which side to go so we decrease
our search space by moving low to right and high to left by 1 units.

TIME = O(LOGN) -> BEST CASE,  O(N) -> WORST CASE(when all elements are equal).

*/

class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int low = 0, high = n - 1;
        while(high - low > 1){
            int mid = low + (high - low)/2;
            if(a[low] == a[mid] and a[mid] == a[high]){
                low ++; high --; continue;
            }
            if(a[low] <= a[mid] and a[mid] <= a[high]) return a[low];
            if(a[low] <= a[mid]) low = mid;
            else high = mid;
        }
        return min(a[low], a[high]);
    }
};