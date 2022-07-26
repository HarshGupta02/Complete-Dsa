// METHOD 1:

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    // pair = {min,max}
    
    pair<int,int> f(Node* root,bool &is){
        if(root == NULL) return {INT_MIN,INT_MAX};
        if(root -> left == NULL and root -> right == NULL) return {root -> data,root -> data};
        if(root -> left != NULL and root -> right == NULL){
            auto curr = f(root -> left,is);
            int mini = curr.first , maxi = curr.second;
            if(maxi < root -> data) return {mini , root -> data};
            is = false;
        }
        if(root -> right != NULL and root -> left == NULL){
            auto curr = f(root -> right,is);
            int mini = curr.first , maxi = curr.second;
            if(mini > root -> data) return {root -> data , maxi};
            is = false;
        }
        auto curr_left = f(root -> left,is);
        auto curr_right = f(root -> right,is);
        int mini_left = curr_left.first , maxi_left = curr_left.second, mini_right = curr_right.first, maxi_right = curr_right.second;
        if(maxi_left < root -> data and root -> data < mini_right) return {mini_left, maxi_right};
        is = false;
    }
    
    bool isBST(Node* root) 
    {
        bool is = true;
        pair<int,int> x = f(root,is);
        return is;
    }
};


// METHOD 2:

class Info{
    public:
    int mini , maxi;
    
    Info(int mini , int maxi){
        this -> mini = mini;
        this -> maxi = maxi;
    }
};

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    Info f(Node* root , bool &is){
        if(root == NULL) return Info(INT_MAX , INT_MIN);
        auto curr_left = f(root -> left,is);
        auto curr_right = f(root -> right,is);
        if(curr_left.maxi < root -> data and root -> data < curr_right.mini){
            return Info(min(curr_left.mini , root -> data) , max(curr_right.maxi , root -> data));
        }
        is = false; return curr_left;
    }
    
    bool isBST(Node* root) 
    {
        bool is = true;
        Info temp = f(root,is);
        return is;
    }
};