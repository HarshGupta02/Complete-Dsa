///  TIME = O((N LOGN)!) , SPACE = O(1).

/*

HERE WE USED THE CONCEPT THAT WE STORE EACH DIGIT OF THE FINAL ANS IN ONE OF THE NODES BY MULTIPLYING THE CURRENT i 
WITH THE DATA OF THE NODES AND DOING %10 AND CARRY = DATA / 10 AND WE KEEP ON DOING THIS.

*/

class Node{
public:
  int data;
  Node *prev;
  Node(int x){
      data = x;
      prev = NULL;
  }
};

void Multiply(Node * tail , int n){
    Node *temp = tail , *prevNode = tail;
    int carry = 0;
    while(temp != NULL){
        int x = temp->data * n + carry;
        temp->data = x % 10;
        carry = x / 10;
        prevNode = temp;
        temp = temp->prev;
    }
    while(carry != 0){
        prevNode->prev = new Node(carry % 10);
        carry /= 10;
        prevNode = prevNode -> prev;
    }
}

void print_factorial(Node *tail ,vector<int>&ans){
    if(tail == NULL) return;
    print_factorial(tail->prev,ans);
    ans.push_back(tail->data);
}

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>ans;
        Node tail(1);
        for(int i = 2; i <= N; i ++){
            Multiply(&tail , i);
        }
        print_factorial(&tail ,ans);
        return ans;
    }
};