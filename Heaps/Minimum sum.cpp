// METHOD 1:

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* reverseList(Node *head)
    {
        Node* p1 = head;
        if(p1 -> next == NULL) return p1;
        Node* p2 = p1 -> next;
        p1 -> next = NULL;
        Node* p3 = p2 -> next;
        while(p3 != NULL){
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p2 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
    void add(int &carry , int sum, Node* &curr){
        carry = (sum / 10);
        int val = sum % 10;
        Node* new_node = new Node(val);
        curr -> next = new_node;
        curr = new_node;
    }
    
     Node* addTwoLists( Node* first,  Node* second)
    {
        first = reverseList(first); second = reverseList(second);
         Node* p1 = first;
         Node* p2 = second;
        int carry = 0;
         Node* head = new Node(-1);
         Node* curr = head;
        while(p1 != NULL and p2 != NULL){
            int sum = p1 -> data + p2 -> data + carry;
            add(carry,sum,curr);
            p1 = p1 -> next; p2 = p2 -> next;
        }
        while(p1 != NULL){
            int sum = p1 -> data + carry;
            add(carry,sum,curr);
            p1 = p1 -> next;
        }
        while(p2 != NULL){
            int sum = p2 -> data + carry;
            add(carry,sum,curr);
            p2 = p2 -> next;
        }
        if(carry != 0){
             Node* temp = new Node(carry);
            curr -> next = temp;
        }
        head = head -> next;
        head = reverseList(head);
        return head;
    }

class Solution{   
public:
using ll = long long int;
    string solve(int arr[], int n) {
        if(n == 1) return to_string(arr[0]);
        sort(arr , arr + n);
        Node* head1 = new Node(-1);
        Node* head2 = new Node(-1);
        Node* curr1 = head1 , *curr2 = head2;
        for(int i = 0; i < n ; i ++){
            if(i % 2 == 0){
                Node* temp = new Node(arr[i]);
                curr1 -> next = temp;
                curr1 = temp;
            }else{
                Node* temp = new Node(arr[i]);
                curr2 -> next = temp;
                curr2 = temp;
            }
        }
        head1 = head1 -> next; head2 = head2 -> next;
        Node* head =  addTwoLists(head1,head2);
        string ans = "";
        while(head != NULL and head -> data == 0){
            head = head -> next;
        }
        while(head != NULL){
            ans.push_back(head -> data + '0');
            head = head -> next;
        }
        return ans;
    }
};

// METHOD 2:

class Solution{   
public:
    string solve(int arr[], int n) {
        string ans;
        int carry = 0;
        sort(arr, arr + n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i] + carry;
            if (i)i--, cur += arr[i];
            carry = cur / 10, cur %= 10;
            ans.push_back(char(cur + '0'));
        }
        if (carry)ans.push_back(char(carry + '0'));
        while (ans.back() == '0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};