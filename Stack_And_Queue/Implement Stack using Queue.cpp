/*
implement stack using 2 queue. => 

here we take 2 queue q1 and q2 and then we do the push operation of stack into q1 so now our
latest inserted element comes at end . but during popping , it should be the first element and
popping is done via the second queue q2.

so we implement push operation of stack using q1 and pop operation using q2.

so we transfer all elements from q2 to q1 so they are inserted at back and the pushed element
in q1 automatically comes at front. and now we just swap the elements of q1 and q2 . so we now have
the pushed element in front of q2 and now we can do the pop operation of queue on q2 and the latest
pushed element is popped out just like usual stack.

so before inserting anything in q1 , it is assured that q1 is empty and it remains empty even after
each pushed operation.

here we can replace q1 and q2 . does not matter.

*/

void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty()){
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
    }
    swap(q1,q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int rmv = q1.front();
    q1.pop();
    return rmv;
}



/*
implement stack using 1 queue =>

insert the element into a queue. keep on popping elements from queue and keep pushing it in back
of queue for sz - 1 times. this ensures that the latest pushed element comes in the front of the 
queue. now we can simply pop the element. works just like stack as the last inserted element is
popped first.

*/

void QueueStack :: push(int x)
{
    q.push(x);
    int sz = q.size() - 1;
    while(sz --){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int QueueStack :: pop()
{
    if(q.empty()) return -1;
    int rmv = q.front();
    q.pop();
    return rmv;
}
