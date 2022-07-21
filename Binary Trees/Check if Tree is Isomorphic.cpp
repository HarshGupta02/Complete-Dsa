/*
if both are NULL so they are isomorphic . if anyone of them is null so they are not
isomorphic. 
now we have 2 options , either swap or not. if we don't swap so we travel left of 
both and right of both. if both return true so it means we don't need to swap.

if we swap , so we travel left of first and right of second and right of first and 
left of second  and if both return true so it means we have to swap.

so we either will have to swap or not have to swap.

*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL and root2 == NULL) return true;
        if(root1 == NULL or root2 == NULL) return false;
        if(root1 -> data != root2 -> data) return false;
        // not swap
        bool a = isIsomorphic(root1 -> left,root2 -> left) and isIsomorphic(root1 -> right,root2 -> right);
        // swap
        bool b = isIsomorphic(root1 -> left,root2 -> right) and isIsomorphic(root1 -> right, root2 -> left);
        return a or b;
    }
};