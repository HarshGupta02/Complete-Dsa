/*
Here we used the same fact that if both max_left < root -> data and root -> data < 
min_right so it is a bst and it's size = left.sz + right.sz + 1.
else if it is not a bst then all the subtrees above it cannot be a bst so we assign
a INT_MIN to min and INT_MAX to max so that the root's data condition is never true
and just max(left.sz and right.sz) is passed above to the parent.
*/

class Info{
    public:
    int mini , maxi , sz;
    
    Info(int mini , int maxi , int sz){
        this -> mini = mini;
        this -> maxi = maxi;
        this -> sz = sz;
    }
    
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    Info f(Node* root){
        if(root == NULL) return Info(INT_MAX , INT_MIN, 0);
        auto curr_left = f(root -> left);
        auto curr_right = f(root -> right);
        if(curr_left.maxi < root -> data and root -> data < curr_right.mini){
            return Info(min(curr_left.mini , root -> data) , max(curr_right.maxi , root -> data) , curr_left.sz + curr_right.sz + 1);
        }
        return Info(INT_MIN,INT_MAX,max(curr_left.sz , curr_right.sz));
        
    }
    
    int largestBst(Node *root)
    {
        return f(root).sz;
    }
};