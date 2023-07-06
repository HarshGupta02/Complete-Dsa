// METHOD 1:

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void inorder(Node* root , vector<int> &v){
        if(root == NULL) return;
        inorder(root -> left,v);
        v.push_back(root -> data);
        inorder(root -> right,v);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>a,b,c;
        inorder(root1,a); inorder(root2,b);
        int n = a.size() , m = b.size();
        int i = 0 , j = 0;
        while(i < n and j < m){
            if(a[i] < b[j]){
                c.push_back(a[i]); i ++;
            }else if(a[i] > b[j]){
                c.push_back(b[j]); j ++;
            }else{
                c.push_back(a[i]); c.push_back(b[j]); i ++; j ++;
            }
        }
        while(i < n){
            c.push_back(a[i]); i ++;
        }
        while(j < m){
            c.push_back(b[j]); j ++;
        }
        return c;
    }
};


// METHOD 2:

class BSTIterator{
public:
    stack<Node*> stk;
    
    int Top() {
        return stk.top() -> data;
    }
    
    void push(Node* root) {
        while(root != NULL) {
            stk.push(root);
            root = root -> left;
        }
    }
    
    BSTIterator(Node* root) {
        push(root);
    }
    
    void next() {
        Node* node = stk.top(); stk.pop();
        push(node -> right);
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
};

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2){
        BSTIterator p(root1), q(root2);
        vector<int> ans;
        int a, b;
        while(p.hasNext() and q.hasNext()) {
            a = p.Top(), b = q.Top();
            if(a <= b) {
                ans.push_back(a);
                p.next();
            }else {
                ans.push_back(b);
                q.next();
            }
        }
        while(p.hasNext()) {
            a = p.Top();
            ans.push_back(a);
            p.next();
        }
        while(q.hasNext()) {
            b = q.Top();
            ans.push_back(b);
            q.next();
        }
        return ans;
    }
};