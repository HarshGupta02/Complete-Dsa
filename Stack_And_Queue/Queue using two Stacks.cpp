/*
implement a queue using 2 stacks =>

first we transfer all the elements from s1 to s2 and then we insert the element
into s1 and then transfer all elements from s2 to s1 and so in this way it
appears that an element was added at the back of s1 and then we do pop operation
on s1 and the element that was inserted first , got popped off first.

*/

void StackQueue :: push(int x)
{
    while(!s1.empty()){
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }
    s1.push(x);
    while(!s2.empty()){
        int temp = s2.top();
        s2.pop();
        s1.push(temp);
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
    int rmv =s1.top();
    s1.pop();
    return rmv;
}