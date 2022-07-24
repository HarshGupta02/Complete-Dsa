// METHOD 1: TIME = O(N) , SPACE = O(N)

class Solution
{
public:

    void f(Node* root , vector<Node*>&ans){
        if(root == NULL) return;
        f(root -> left,ans);
        ans.push_back(root);
        f(root -> right,ans);
    }

    void populateNext(Node *root)
    {
        vector<Node*>ans;
        f(root,ans);
        for(int i = 0; i + 1 < ans.size(); i ++){
            ans[i] -> next = ans[i + 1];
        }
    }
};

// METHOD 2 : TIME = O(N) , SPACE = O(HEIGHT OF TREE)

/*
HERE WE KNOW THAT IN INORDER TRAVERSAL AFTER COMING FROM LEFT , THE DATA ELEMENT
COMES AND WE PREV AS CURR AND THE RIGHT AS CURR SO AS WE KEEP ON RETURNING , WE KEEP
ON ASSIGNING LAST RETURNED NODE AS PREV NODE.
*/

class Solution
{
public:

    void f(Node* root , Node* &prev){
        if(root == NULL) return;
        f(root -> left,prev);
        if(prev != NULL) prev -> next = root;
        prev = root;
        f(root -> right,prev);
    }

    void populateNext(Node *root)
    {
        Node* prev = NULL;
        f(root,prev);
    }
};