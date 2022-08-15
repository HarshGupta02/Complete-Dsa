class Solution{
  public:
    
    struct Node* lcaa(struct Node* root, int first, int second){
        if(root == NULL or root -> data == first or root -> data == second) return root;
        struct Node* a = lcaa(root -> left, first, second);
        struct Node* b = lcaa(root -> right, first, second);
        if(a == NULL and b == NULL) return NULL;
        if(a == NULL) return b;
        if(b == NULL) return a;
        return root;
    }
    
    void f(struct Node* root, int first, string &s, string temp){
        if(root == NULL) return;
        if(root -> data == first){
            s = temp;
            return;
        }
        f(root -> left, first, s, temp + 'L');
        f(root -> right, first, s, temp + 'R');
    }
     
    int NumberOFTurns(struct Node* root, int first, int second)
    {
        struct Node* lca = lcaa(root, first, second);
        string s1 = "", s2 = "";
        string temp = "";
        f(lca, first, s1, temp); // calculate path from lca to first node
        f(lca, second, s2, temp);
        reverse(s1.begin(), s1.end());
        s1 += s2;
        int ans = 0;
        for(int i = 0; i + 1 < s1.size(); i ++){
            if(s1[i] != s1[i + 1]) ans ++;
        }
        return ans == 0 ? -1 : ans;
    }
};