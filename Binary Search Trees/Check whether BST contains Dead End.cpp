// METHOD 1: TIME = O(4 * N) , SPACE = O(4 * N)

void f(Node* root,vector<int> &a){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL){
        int val = root -> data;
        a.push_back(val - 1);
        a.push_back(-1);
        a.push_back(val);
        a.push_back(-1);
        a.push_back(val + 1);
        return;
    }
    f(root -> left,a);
    a.push_back(root -> data);
    f(root -> right,a);
}

bool isDeadEnd(Node *root)
{
    vector<int>a;
    f(root,a);
    int sz = a.size();
    for(int i = 0; i < sz; i ++){
        if(i - 1 >= 0 and i + 1 < sz and a[i - 1] == -1 and a[i + 1] == -1){
            int left = a[i - 2] , right = a[i + 2];
            if((left == 0 or (i - 3 >= 0 and a[i - 2] == a[i - 3])) and (i + 3 < sz and a[i + 3] == a[i + 2])){
                return true;
            }
        }
    }
    return false;
}

/// METHOD 2 : TIME = O(N) , SPACE = O(N)

/*
Here we check if for all the leaf nodes if data - 1 and data + 1, exist in the mp
or not. if both exist then only it is a dead end.
*/

void f(Node* root, map<int,int> &mp1, map<int,int> &mp2){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL){
        mp1[root -> data] ++; mp2[root -> data] ++;
        return;
    }
    f(root -> left,mp1,mp2);
    mp1[root -> data] ++;
    f(root -> right,mp1,mp2);
}

bool isDeadEnd(Node *root)
{
    map<int,int>mp1,mp2;
    f(root,mp1,mp2);
    for(auto it : mp2){
        if((mp1[it.first - 1] == 1 or (it.first - 1) == 0) and (mp1[it.first + 1] == 1)) return true;
    }
    return false;
}

// METHOD 3: TIME = O(N) , SPACE = O(HEIGHT OF TREE).

/*
Here we are assume that the root node as value that lies within the range 
1 - INF and we see that the node on the left always has value from 1 - (data - 1)
and node on right has value ranging from (data + 1 to INF) and we do so 
recursively for all the nodes and if any leaf node has left and right range values
equal to node's data so it is a dead end.
*/

bool f(Node* root , int low , int high){
    if(root == NULL) return false;
    if(root -> left == NULL and root -> right == NULL){
        if(low == root -> data and high == root -> data) return true;
        return false;
    }
    return f(root -> left,low , root -> data - 1) or f(root -> right,root -> data + 1, high);
}

bool isDeadEnd(Node *root)
{
    int low = 1 , high = INT_MAX;
    return f(root,low,high);
}



