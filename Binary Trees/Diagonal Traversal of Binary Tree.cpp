/*
here we used the fact that we always go to the right from the nodes on the 
left side.

so each time we traverse the right side , if we find any node on the left
then they are inserted in a queue so that again we can go to right from them
by popping the elements one by one.

this also ensures that those elements that came first in the queue will be
executed first and they will be higher in the diagonal's height.

*/

vector<int> diagonal(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        while(curr != NULL){
            if(curr -> left != NULL) q.push(curr -> left);
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
    }
    return ans;
    
}