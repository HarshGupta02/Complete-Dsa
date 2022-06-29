void f(queue<int> &q , int &cnt){
    if(cnt == 0) return;
    int x = q.front();
    q.pop();
    cnt --;
    f(q,cnt);
    q.push(x);
}

queue<int> modifyQueue(queue<int> q, int k) {
    int sz = q.size();
    int cnt = k;
    f(q,cnt);
    cnt = sz - k;
    while(cnt --){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}