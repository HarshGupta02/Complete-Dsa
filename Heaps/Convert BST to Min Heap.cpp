// TIME = O(N) , SPACE = O(N)

/*
so basically if we see the conditions on min heap we come to know that the 
root element must be smallest follwed by left child which is greater than
root and followed by right child which is greater than the left child.

so this occurs if we have a preorder traversal(root , root -> left ,
root -> right).

so we first find the inorder traversal of the BST which comes out to be a 
sorted array and then we update the value of the nodes in bst with the given
array in preorder traversal of the bst.
*/

void Inorder(BinaryTreeNode* &root , vector<int> &inorder){
    if(root == NULL) return;
    Inorder(root -> left, inorder);
    inorder.push_back(root -> data);
    Inorder(root -> right , inorder);
}

void Preorder(BinaryTreeNode* &root , vector<int> &inorder , int &idx){
    if(root == NULL) return;
    root -> data = inorder[idx]; idx ++;
    Preorder(root -> left, inorder, idx);
    Preorder(root -> right, inorder, idx);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int>inorder;
    Inorder(root,inorder);
    int idx = 0;
    Preorder(root , inorder, idx);
    return root;
}