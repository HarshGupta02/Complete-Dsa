// TIME = O(3 * N) AS WE TRAVERSED EACH NODE AT MAX 3 TIMES , SPACE = O(N) , JUST FOR
// CREATING NODES...

/*
HERE WE USED THE PROPERTY THAT EACH NODE HAS A UPPER BOUND TO IT LIKE FOR ROOT NODE
IT IS INT_MAX AND FOR IT'S LEFT CHILD, THE UPPER BOUND IS ROOT -> VAL AND FOR RIGHT
CHILD, THE UPPER BOUND IS BOUND OF PARENT'S NODE.

*/

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    
    Node* f(int pre[], int size, int &i, int upper){
        if(i == size or pre[i] > upper) return NULL;
        Node* root = newNode(pre[i ++]);
        root -> left = f(pre, size, i, root -> data);
        root -> right = f(pre, size, i, upper);
        return root;
    }
    
    Node* post_order(int pre[], int size)
    {
        int upper = INT_MAX;
        int i = 0;
        return f(pre, size, i, upper);
    }
};