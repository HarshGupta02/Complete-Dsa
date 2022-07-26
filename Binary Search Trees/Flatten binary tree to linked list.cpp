// METHOD 1 : TIME = O(N) , SPACE = O(N)

/*
Here we used needed the preorder traversal which is data , left , right. so here 
we first traversed right , then left because after coming from a node's right , 
i can assign the right of the node to prev and go to left as in the final linked
list , each node's right should point to next node so the right pointer should 
be traversed first. and as we return from a node , we assign the current node to 
prev.
*/

class Solution
{
    public:
    Node* prev = NULL;
    void flatten(Node *root)
    {
        if(root == NULL) return;
        flatten(root -> right);
        flatten(root -> left);
        
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};


// METHOD 2 : MORRIS TRAVERSAL : TIME = O(N) , SPACE = O(1)

/*
Here we first find the right most node in the left subtree of the given node as
this will be the node after which current's node right will come. so we join a thread
btw both and then assign curr -> right to curr -> left so that we can move first
left as we move in preorder and after processing both right and left , we assign
the curr -> left = null;
*/

class Solution
{
    public:
    
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr != NULL){
            if(curr -> left != NULL){
                Node* prev = curr -> left;
                while(prev -> right != NULL){
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};