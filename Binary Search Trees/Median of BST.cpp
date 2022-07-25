int Morris_Traversal_1(Node* root){
    int cnt = 0;
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            cnt ++; 
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
                cnt ++;
                curr = curr -> right;
            }
        }
    }
    return cnt;
}

float Morris_Traversal_2(Node* root, int n){
    int target = (n % 2 == 1) ? (n + 1)/2 : n/2; 
    int cnt = 0;
    Node* curr = root;
    Node* ans;
    Node* nxt;
    while(curr != NULL){
        if(curr -> left == NULL){
            cnt ++;
            if(cnt == target){
                ans = curr;
            }
            if(cnt == target + 1){
                nxt = curr;
            }
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
                cnt ++;
                if(cnt == target){
                    ans = curr;
                }
                if(cnt == target + 1){
                    nxt = curr;
                }
                curr = curr -> right;
            }
        }
    }
    if(n % 2 == 1) return ans -> data;
    return (ans -> data + nxt -> data)/2.0;
}

float findMedian(struct Node *root)
{
    int n = Morris_Traversal_1(root);
    float ans = Morris_Traversal_2(root,n);
    return ans;
}