class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int x = k;
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1; j < n ; j ++){
                int left = j + 1 , right = n - 1;
                while(left < right){
                    int curr_sum = arr[i] + arr[j] + arr[left] + arr[right];
                    if(curr_sum < x){
                        left ++; continue;
                    }
                    if(curr_sum > x){
                        right --; continue;
                    }
                    vector<int>curr = {arr[i] , arr[j] , arr[left] , arr[right]};
                    ans.push_back(curr);
                    int temp = arr[left];
                    while(left < n and arr[left] == temp) left ++;
                    temp = arr[right];
                    while(right >= 0 and arr[right] == temp) right --;
                }
                while(j + 1 < n and arr[j + 1] == arr[j]) j ++;
            }
            while(i + 1 < n and arr[i + 1] == arr[i]) i ++;
        }
        return ans;
    }
};