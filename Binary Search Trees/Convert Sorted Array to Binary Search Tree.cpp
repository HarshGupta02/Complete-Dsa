/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* f(int low, int high, int n, vector<int> &nums){
        int mid = low + (high - low)/2;
        int x = nums[mid];
        TreeNode* new_node = new TreeNode(x);
        if(low == mid and high == mid) return new_node;
        if(low == mid){
            new_node -> left = NULL;
            TreeNode* new_right = new TreeNode(nums[high]);
            new_node -> right = new_right;
            return new_node;
        }
        new_node -> left = f(low , mid - 1, n, nums);
        new_node -> right = f(mid + 1, high, n, nums);
        return new_node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        return f(low, high, n, nums);
    }
};

/*

-10 -3 0 5 9

try to take the middle element and recursively solve for left half and right half and if we do this
for each node, so all the elements in left and right half will be uniformly distributed so it will
become a height balanced bst.
*/