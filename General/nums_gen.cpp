#include<bits/stdc++.h>
using namespace std;
int main(){
    const int LEN = 10;
    const int L = 1, R = 50;
    vector<int> nums(LEN);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(L, R);
    for(int i = 0; i < LEN; i ++) nums[i] = distr(gen);
    for(auto it : nums) cout << it << " ";
    return 0;
}