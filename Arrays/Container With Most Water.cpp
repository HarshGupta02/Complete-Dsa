class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int left = 0, right = n - 1;
        int ans = -1;
        while(left <= right){
            int height = min(a[left], a[right]);
            int width = right - left;
            ans = max(ans, height * width);
            if(a[left] <= a[right]) left ++;
            else right --;
        }
        return ans;
    }
};