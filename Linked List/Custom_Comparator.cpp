#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int marks, roll;
    Student(string name, int marks, int roll) {
        this -> name = name;
        this -> marks = marks;
        this -> roll = roll;
    }

    void print() {
        cout << name << " " << marks << " " << roll << endl;
    }
};

bool cmp(int a, int b) {
    return (a > b);
}

bool cmp1(Student a, Student b) {
    if(a.marks == b.marks) return a.name < b.name;
    return a.marks > b.marks; 
}

class cmp2 {
public:
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

class cmp3{
public:
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

int main(){
    vector<int> a = {4,6,3,7,9,5,4,3};
    vector<Student> b;
    b.push_back(Student("XYZ", 99, 1));
    b.push_back(Student("ABC", 95, 2));
    // cmp and cmp1 are custom comparator functions
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp1);
    for(auto it : a) cout << it << " ";
    for(auto it : b) it.print();
    set<int, cmp2> st;
    st.insert(2); st.insert(1); st.insert(3);
    for(auto it : st) cout << it << " ";
    cout << endl;
    // max heap
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, cmp3> pq;
    // so vector<int> is a container of type vector in which highest priority element 
    // always lies at the end of the container
    // so in max heap, max element lies at last hence sort in increasing order
    // and in min heap, min element lies at last hence sort in decreasing order.
    pq.push(1); pq.push(5); pq.push(2);
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}