class Solution{
public:
    int idx = 0;
    
    Node* f(int n, string s){
        if(idx >= n or s[idx] == ')') {
            idx ++;
            return NULL;
        }
        int num = 0;
        while(idx < n and s[idx] >= '0' and s[idx] <= '9'){
            num = num * 10 + (s[idx] - '0');
            idx ++;
        }
        Node* head = new Node(num);
        if(idx < n and s[idx] == '('){
            idx ++;
            head -> left = f(n, s);
        }
        if(idx < n and s[idx] == '('){
            idx ++;
            head -> right = f(n, s);
        }
        idx ++; // why ??
        return head;
    }
    
    Node *treeFromString(string s){
        int n = s.size();
        return f(n, s);
    }
};