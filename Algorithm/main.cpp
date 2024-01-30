#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n, m, s, e;
int cnt1, cnt2;
vector<vector<int>> vec;
//vector<vector<int>> check;
//int map[10001][10001];
vector<int> resetVec;
int visited[10001];
int check[10001];
queue<int> q;
map<int, int> mp;

void bfs(int num) {
	if (visited[num] != 0) return;
	visited[num] = 1;
	q.push(num);
	check[num] = 0;

	while (!q.empty()) {
		int cur = q.front();
		if (num == s && cur == e) break;
		if (num == e && cur == s) 
			break;
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];
			if (!visited[next]) {
				visited[next] = 1;
				check[next] = check[cur] + 1; 
				if (mp.find(check[next]) != mp.end()) 
					resetVec.push_back(next);
				else mp.insert(make_pair(check[next], next));
				q.push(next);
			}
		}
	}

	if (resetVec.size() != 0) {
		for (int i = 0; i < resetVec.size(); i++) {
			visited[resetVec[i]] = 0;
		}
	}

	if (!q.empty()) {
		while (!q.empty()) {
			int a = q.front();
			visited[a] = 0;
			q.pop();
		}
	}
	if (num == s) {
		cnt1 = check[e];
		visited[s] = 0;
		visited[e] = 0;
	}
	else cnt2 = check[s];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vec.assign(n+1, vector<int>());	
	//check.assign(n+1, vector<int>());	

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cin >> s >> e;

	for (int i = 0; i < vec[i].size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	bfs(s);
	bfs(e);

	/*for (int i = 0; i <= n; i++) {
		cout << check[i] << " ";
	}

	cout << "\n" << cnt1;*/
	cout << cnt1 + cnt2;

}
