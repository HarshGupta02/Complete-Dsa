class Solution {
public:
    /*
    brute force = for each i, look for extreme left which is greater than a[i] and look for 
    extreme right which is greater than a[i] and then take the min of both and subtract by a[i].
    this gives the amount of water which can be stored above the a[i]th block.
    
    ans += min(left_max, right_max) - a[i]. for all i = 0....n - 1
    
    */
    
    int trap(vector<int>& a) {
        int n = a.size();
        int left = 0, right = n - 1;
        int left_max = -1, right_max = -1;
        // for each a[i], left_max ensures that whether water will be filled btw
        // a[i] and left_max or not. same goes for right_max.
        int ans = 0;
        while(left <= right){
            if(a[left] <= a[right]){ /// this line ensures that there is an element on right which is 
            // greater than curr element and so water can be stored above the curr element's height.
                if(a[left] > left_max) left_max = a[left]; 
                else ans += (left_max - a[left]); // this ensure that there is an element on left which is greater than curr
                // element and so water can be stored above the curr element's height.
                left ++;
                // the new left will have assurity that if l has reached here , then it must have crossed the building which updated
                // the left_max and there was an element on it's right and since the new left is less than left_max , so there will 
                // always be a building on the right which is greater than the new left's height.
            }else{
                if(a[right] > right_max) right_max = a[right];
                else ans += (right_max - a[right]);
                right --;
            }
        }
        return ans;
    }
};