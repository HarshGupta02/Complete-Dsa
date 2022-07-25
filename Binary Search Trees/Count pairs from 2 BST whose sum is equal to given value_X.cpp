class Solution
{
public:

    int countPairs(Node* root1, Node* root2, int x)
    {
        if(root1 == NULL or root2 == NULL) return 0;
        stack<Node*>stk_1,stk_2;
        Node* top_1;
        Node* top_2;
        int ans = 0;
        while(true){
            while(root1 != NULL){
                stk_1.push(root1);
                root1 = root1 -> left;
            }
            while(root2 != NULL){
                stk_2.push(root2);
                root2 = root2 -> right;
            }
            /// here both curr_1 and curr_2 are NULL.
            if(stk_1.empty() or stk_2.empty()) break;
            top_1 = stk_1.top(); top_2 = stk_2.top();
            if(top_1 -> data + top_2 -> data == x){
                stk_1.pop(); stk_2.pop();
                ans ++; root1 = top_1 -> right; root2 = top_2 -> left;
            }else if(top_1 -> data + top_2 -> data < x){
                stk_1.pop();
                root1 = top_1 -> right;
            }else {
                stk_2.pop();
                root2 = top_2 -> left;
            }
        }
        return ans;
    }
};