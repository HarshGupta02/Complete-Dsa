class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr + n , [&](const Item &a , const Item &b) -> bool{
            double x = (double)a.value / a.weight;
            double y = (double)b.value / b.weight;
            return x > y;
        });
        double total_val = 0;
        for(int i = 0; i < n ; i ++){
            if(arr[i].weight < W){
                total_val += arr[i].value;
                W -= arr[i].weight;
            }else{
                double p = (double)arr[i].value / arr[i].weight;
                total_val += p * W;
                break;
            }
        }
        return total_val;
    }
};