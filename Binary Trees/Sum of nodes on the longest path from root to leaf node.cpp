class Solution
{
public:

    void f(Node* root , int curr_len , int &max_len,int curr_sum , int &max_sum){
        if(root == NULL){
            return;
        }
        curr_len += 1;
        curr_sum += root -> data;
        if(root -> left == NULL and root -> right == NULL){
            if(curr_len >= max_len){
                max_len = curr_len;
                max_sum = max(max_sum , curr_sum);
            }
            return;
        }
        f(root -> left,curr_len,max_len,curr_sum,max_sum);
        f(root -> right,curr_len,max_len,curr_sum,max_sum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int curr_len = 0, max_len = -1 , curr_sum = 0 ,max_sum = -1;
        f(root,curr_len,max_len,curr_sum,max_sum);
        return max_sum;
    }
};