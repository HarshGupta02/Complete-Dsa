void f(queue<int> &q , queue<int> &ans){
    if(q.empty()) return;
    int x = q.front();
    q.pop();
    f(q,ans);
    ans.push(x);
}

queue<int> rev(queue<int> q)
{
    queue<int>ans;
    f(q,ans);
    return ans;
}