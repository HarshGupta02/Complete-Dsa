class cmp{
public:
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return (a[0] + a[1] < b[0] + b[1]);
    }
};

using vi = vector<int>;

vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int N, int K){
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	priority_queue<vi, vector<vi>, cmp> pq;
	for(int i = 0; i < K; i ++) pq.push({A[i], B[0], 0});
	vector<int> ans;
	while(!pq.empty() and K --) {
		vi curr = pq.top(); pq.pop();
		ans.push_back(curr[0] + curr[1]);
		if(curr[2] == N - 1) continue;
		pq.push({curr[0], B[curr[2] + 1], curr[2] + 1});
	}
	return ans;
}