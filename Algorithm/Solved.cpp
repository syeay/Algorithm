//24,01.16
//백준 : 2178(미로 탐색)
#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
vector<vector<int>> v;
queue<pair<int, int>> q;
vector<vector<int>> visited;
vector<vector<int>> dist;

// 위, 오른쪽, 아래, 왼쪽
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {
	q.push(pair<int, int>(x, y));
	visited[x][y] = 1;
	dist[x][y] = 1;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (v[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push(pair<int, int>(nx, ny));
				dist[nx][ny] = dist[curx][cury] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	v.assign(n + 1, vector<int>(m));
	dist.assign(n, vector<int>(m));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			visited[i][j] = 0;
			if (str[j] == '1')
				v[i][j] = 1;
			else
				v[i][j] = 0;
		}
	}

	bfs(0, 0);

	cout << dist[n - 1][m - 1];
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}
#endif


//24.01.15
//백준 : 24480(깊이우선탐색-2)
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
int cnt = 0;
vector<vector<int>> v1;
vector<int> v2;
vector<bool> visited;

void dfs(int num) {
	if (visited[num]) return;
	visited[num] = true;
	cnt++;
	v2[num - 1] = cnt;

	for (int i = 0; i < v1[num].size(); i++) {
		dfs(v1[num][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;
	v1.assign(n + 1, vector<int>());
	v2.assign(n + 1, 0);
	visited.assign(n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		v1[u].push_back(v);
		v1[v].push_back(u);
	}

	for (int i = 0; i <= n; i++) {
		sort(v1[i].begin(), v1[i].end(), greater<>());
	}

	dfs(r);

	for (int i = 0; i < n; i++) {
		cout << v2[i] << "\n";
	}

	return 0;
}
#endif

// 백준 : 2667(단지 번호 붙이기)
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result = 0, result_cnt = 0;
// 왼 위 오 아래
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> v;
vector<int> result_vec;
vector<vector<int>> visited;

void input() {
	cin >> n;
	v.assign(n, vector<int>(n));
	visited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		// 한 줄의 입력을 string으로 받기
		string arr;
		cin >> arr;
		for (int j = 0; j < arr.length(); j++) {
			// 문자는 '' 문자열일 때만 ""
			if (arr[j] == '1')
				v[i][j] = 1;
			else
				v[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		// 기준점을 중심으로 동서남북 체크
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 움직인 값이 2차원 배열을 벗어날 경우
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;

		// 아파트가 있고 방문하지 않았을 경우
		if (v[nx][ny] == 1 && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			result_cnt++;
			dfs(nx, ny);
		}
	}
}

int main() {
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1 && visited[i][j] == 0) {
				// 첫 시작점 방문 true
				visited[i][j] = 1;
				result_cnt = 1;
				dfs(i, j);
				result_vec.push_back(result_cnt);
				result++;
			}
		}
	}
	// 오름차순 정렬
	sort(result_vec.begin(), result_vec.end());
	cout << result << "\n";
	for (int i = 0; i < result_vec.size(); i++) {
		cout << result_vec[i] << "\n";
	}
	return 0;
}
#endif