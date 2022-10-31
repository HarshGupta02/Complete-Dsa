class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while(n != 0){
            v.push_back(n % 10);
            n/=10;
        }
        reverse(v.begin(), v.end());
        n = v.size();
        bool found = false;
        int idx = -1;
        for(int i = n - 2; i >= 0; i --){
            if(v[i] >= v[i + 1]) continue;
            found = true;
            idx = i; break;
        }
        if(!found) return -1;
        int start = -1;
        for(int i = n - 1; i >= idx; i --){
            if(v[i] > v[idx]){
                start = i + 1;
                swap(v[i], v[idx]);
                break;
            }
        }
        reverse(v.begin() + idx + 1, v.end());
        long long int num = 0;
        for(int i = 0; i < v.size(); i ++){
            num = 10 * num + v[i];
        }
        if(num > INT_MAX) return -1;
        return num;
    }
};

// 653754 => 654753

/*

if n has 1 digit so ans = -1
if n has 2 digits so => (ab)

if(a == b) ans = -1
else if (ba) > (ab) so ans = ba else ans = -1

if n has 3 digits so => (abc)

abc, acb, bac, bca, cab, cba

1. we first find the nge of each digit in the num and if we find any digit
which has nge != -1 so swap both the digits and keep on doing this for each
element and then in last, return the answer.




*/