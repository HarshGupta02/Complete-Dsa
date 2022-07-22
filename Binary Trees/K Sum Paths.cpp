/*
Could use dp if smaller constraints on K.

Here , as we visit a node , we insert it into an existing vector and find the 
sum from the back of the current vector and check if sum ==k . if yes so cnt ++;
we iterate from back because it ensures that the answer path will begin from the 
current node and go up the tree.

*/

class Solution{
  public:
  
    void f(Node* root , int k , vector<int> &temp , int &cnt){
        if(root == NULL) return;
        temp.push_back(root -> data);
        f(root -> left,k,temp,cnt);
        f(root -> right,k,temp,cnt);
        int sum = 0;
        int sz = temp.size();
        for(int i = sz - 1; i >=0 ; i --){
            sum += temp[i];
            if(sum == k) cnt ++;
        }
        temp.pop_back();
    }
  
    int sumK(Node *root,int k)
    {
        vector<int>temp;
        int cnt = 0;
        f(root,k,temp,cnt);
        return cnt;
    }
};