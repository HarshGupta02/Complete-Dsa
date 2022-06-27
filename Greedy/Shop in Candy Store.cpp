class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies , candies + N);
        int mini = 0;
        int i = 0, j = N - 1;
        while(i <= j){
            mini += candies[i];
            i ++;
            j -= K;
        }
        i = 0 , j = N - 1;
        int maxi = 0;
        while(i <= j){
            maxi += candies[j];
            j --; i += K;
        }
        vector<int>ans = {mini , maxi};
        return ans;
    }
};

// 1 2 3 4

// 1 2 3 4 5 6   k = 3