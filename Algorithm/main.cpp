#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r, cnt=0;
vector<vector<int>> vec;
queue<int> q1;
vector<int> vec2;
vector<bool> visited;

void bfs(int num) {
	q1.push(num);
	visited[num] = true;

	while (!q1.empty()) {
		int cur = q1.front();
		q1.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];
			if (!visited[next]) {
				cnt++;
				vec2[next-1] = cnt;
				q1.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
	
	cin >> n >> m >> r;
	vec.assign(n+1, vector<int>());
	visited.assign(n+1, false);
	vec2.assign(n+1, 0);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	cnt = 1;
	vec2[r-1] = cnt;
	bfs(r);

	for (int i = 0; i < n; i++) {
		cout << vec2[i] << "\n";
	}
	return 0;
}