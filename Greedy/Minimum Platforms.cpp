////  TIME = O(N * LOGN) , SPACE = O(1)

/// HERE WE USED THE CONCEPT THAT IF ARRIVAL OF A TRAIN IS BEFORE THE DEPARTURE
/// OF ANOTHER TRAIN THEN WE HAVE TO ASSIGN A NEW PLATFORM TO THE TRAIN BUT IF
/// OPP IS TRUE THEN WE HAVE TO DECREASE CURRENT_OCCUPIED PLATFORMS , THIS ENSURES
/// MINIMUM ALLOTMENT OF PLATFORMS TO THE TRAINS.

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr , arr + n);
        sort(dep , dep + n);
        int curr = 1 , nax = -1;
        int i = 1 , j = 0;
        while(i < n){
            if(arr[i] <= dep[j]){
                curr ++; i ++;
            }else{
                curr --; j ++;
            }
            nax = max(nax, curr);
        }
        return nax;
    }
};