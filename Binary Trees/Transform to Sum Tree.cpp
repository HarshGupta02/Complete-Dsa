class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int f(Node* &node){
        if(node == NULL) return 0;
        int temp = node -> data;
        node -> data = f(node -> left) + f(node -> right);
        return temp + node -> data;
    }
    
    void toSumTree(Node *node)
    {
        int x = f(node);
    }
};