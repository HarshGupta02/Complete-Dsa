//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top1 + 1 != top2){
        top1 ++;
        arr[top1] = x;
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top2 - 1 != top1){
        top2 --;
        arr[top2] = x;
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    int removed_element;
    if(top1 != -1){
        removed_element = arr[top1];
        top1 --;
        return removed_element;
    }
    return -1;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    int removed_element;
    if(top2 != size){
        removed_element = arr[top2];
        top2 ++;
        return removed_element;
    }
    return -1;
}