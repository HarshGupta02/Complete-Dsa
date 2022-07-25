// METHOD 1 : 

class Solution{
public:

int Morris_Traversal(Node* root,int l ,int h){
    int cnt = 0;
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            if(curr -> data >= l and curr -> data <= h) cnt ++;
            curr = curr -> right;
        }else{
            Node* prev = curr -> left;
            while(prev -> right != NULL and prev -> right != curr){
                prev = prev -> right;
            }
            if(prev -> right == NULL){
                prev ->right = curr;
                curr = curr -> left;
            }else{
                prev -> right = NULL;
                if(curr -> data >= l and curr -> data <= h) cnt ++;
                curr = curr -> right;
            }
        }
    }
    return cnt;
}

int getCount(Node *root, int l, int h)
{
    return Morris_Traversal(root,l,h);
}

};

// METHOD 2: 

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
        if(root == NULL) return 0;
        if(root -> data >= l and root -> data <= h) return 1 + getCount(root -> left,l,h) + getCount(root -> right,l,h);
        if(root -> data < l) return getCount(root -> right,l,h);
        return getCount(root -> left,l,h);
    }
};