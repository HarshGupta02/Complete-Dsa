// TIME = O(N), SPACE = O(1)

/*

tnp = numbers of the form 3n
tnp1 = numbers of the form 3n + 1
tnp2 =  numbers of the form 3n + 2

tnc = numbers which are common to 3n and nums[i]
tnp1c = numbers which are common to 3n + 1 and nums[i]
tnp2c = numbers which are common to 3n +2 and nums[i]

so here we process each element and after processing each element, we take AND of nums[i]
and tnp and tnp1 and tnp2 and the bits which are set after taking AND denotes that these
bits we set before also and this number also has set bits so we set the bits off in the 
current number form and set the bits to the next number's form.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int tnp = -1, tnp1 = 0, tnp2 = 0; /// why -1 ??
        for(int i = 0; i < n; i ++){
            int tnc = tnp & nums[i];
            int tnp1c = tnp1 & nums[i];
            int tnp2c = tnp2 & nums[i];
            
            tnp1 = (tnp1 | tnc);
            tnp = (tnp & (~tnc));
                   
            tnp2 = (tnp2 | tnp1c);
            tnp1 = (tnp1 & (~tnp1c));
            
            tnp = (tnp | tnp2c);
            tnp2 = (tnp2 & (~tnp2c));
        }
        return tnp1;
    }
};