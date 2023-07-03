/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertAtCorrectPos(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int y = s.top(); 
    if(y > x) {
        s.pop();
        insertAtCorrectPos(s, x);
        s.push(y);
    }else s.push(x);
}

void go(stack<int> &s) {
    if(s.empty()) return;
    int x = s.top(); s.pop();
    go(s);
    insertAtCorrectPos(s, x);
}

void SortedStack :: sort(){
    go(s);
}