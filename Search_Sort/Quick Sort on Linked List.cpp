void swap(Node* a,Node* b){
       int temp=a->data;
       a->data=b->data;
       b->data=temp;
   }
   Node* partition(Node *l, Node *h){
       //Your code goes here
       Node* pivot=h;
       Node* i=l;
       for(Node* j=l ; j!=h ; j=j->next){
           if(j->data < pivot->data){
               swap(i,j);
               i=i->next;
           }
       }
       swap(i,pivot);
       return i;
   }