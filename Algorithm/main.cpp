#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s, e;
int cnt1, cnt2;
vector<vector<int>> map;
//int map[10001][10001];
int visited[10001];
int check[10001][10001];
queue<int> q;

void bfs(int num) {
	if (visited[num] != 0) return;
	visited[num] = 1;
	q.push(num);
	//check[num][num] = 0;

	while (!q.empty()) {
		int cur = q.front();
		if (cur == e) break;
		q.pop();

		for (int i = 0; i < n; i++) {
			int next = map[cur][i];
			if (!visited[next]) {
				visited[next] = 1;
				check[next][i] = check[cur][i] + 1;
				q.push(next);
			}
		}
	}

	if (!q.empty()) {
		while (!q.empty()) {
			int a = q.front();
			visited[a] = 0;
			q.pop();
		}
	}
	else {
		if (num == s) cnt1 = visited[e];
		else cnt2 = visited[s];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	map.assign(n+1, vector<int>());	

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	/*for (int i = 0; i < sizeof(map[i]) / sizeof(int); i++) {
		sort(map[i], map[i]+(sizeof(map[i]) / sizeof(int)));
	}*/

	/*for (int i = 0; i < n; i++) {
		sort(map[i].begin(), map[i].end());
	}*/


	cin >> s >> e;
	bfs(s);
	bfs(e);

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << cnt1 + cnt2;

}

// 1. �Է��� �޴´�.
// 2. �Է� ���� ������ map�� �ִ´�.
// 3. ��������� �̵� �����ϰ� �ִ´�.
// 4. s�� �Է��Ͽ� bfs�� ������.
// 4-0. �� ���� ��� �����ϸ� ���� ������ �������� ����.
// 4-1. visited�� �湮 ���ڸ� �ø���.
// 5. ���� ������ e�� �����ߴٸ� return �Ѵ�.
// 
// 6. e�� �Է��� bfs�� ������.
// 
//