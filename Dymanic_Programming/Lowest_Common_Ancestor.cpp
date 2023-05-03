#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
const int LOG = 14;
vector<int> children[MAX_N];
int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];

void dfs(int a, int par) {
	for(int b : children[a]) {
		if(b == par) continue;
		depth[b] = depth[a] + 1;
		up[b][0] = a;
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[up[b][j-1]][j-1];
		}
		dfs(b, a);
	}
}

// O(log(N))
int LCA_OPTIMISED(int a, int b) { 
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j];
		}
	}
	if(a == b) return a;
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

// O(N)
int LCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    while(depth[a] != depth[b]) {
        // a = parent[a];
        a = up[a][0];
    }
    while(a != b) {
        // a = parent[a];
        a = up[a][0];
        // b = parent[b];
        b = up[b][0];
    }
    return a;
}

int main() {
	int n;
	cin >> n;
	for(int v = 0; v < n; ++v) {
		int cnt;
		cin >> cnt;
		for(int i = 0; i < cnt; i++) {
			int c;
			cin >> c;
			children[v].push_back(c);
		}
	}
	dfs(0);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA_OPTIMISED(a, b) << "\n";
	}
}