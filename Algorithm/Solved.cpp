//24.01.26
//백준 : 7569번(토마토 3차원)
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, h;
bool bripe = true;
int map[101][101][101];
int visited[101][101][101];
queue<tuple<int, int, int>> q;
vector<int> v;

int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, -1, 0, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

void bfs() {
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			int nc = c + dz[i];

			if (na < 0 || nb < 0 || nc < 0 || na >= h || nb >= n || nc >= m) continue;
			if (map[na][nb][nc] == 0 && visited[na][nb][nc] == 0) {
				visited[na][nb][nc] = 1;
				q.push({ na, nb, nc });
				map[na][nb][nc] = map[a][b][c] + 1;
				v.push_back(map[na][nb][nc]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// 높이, 세로, 가로
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i, j, k });
					visited[i][j][k] = 1;
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					bripe = false;
					break;
				}
				//cout << map[i][j][k] << " ";
			}
			//cout << "\n";
		}
		//cout << "\n";
	}

	if (!bripe) cout << -1;
	else if (v.size() == 0) cout << 0;
	else {
		sort(v.begin(), v.end(), greater<int>());
		cout << v[0] - 1;
	}

	return 0;
}
#endif


//24.01.25
//백준 : 1012번(유기농 배추)
#if 0
#include <iostream>
#include <queue>
using namespace std;

int t, m, n, k, cnt = 0;
int map[51][51];
int visited[51][51];
queue<pair<int, int>> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void reset() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	cnt = 0;
}

void bfs(int x, int y) {
	if (visited[x][y] == 1) return;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = curx + dx[i];
			int newy = cury + dy[i];

			if (newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
			if (map[newx][newy] == 1 && visited[newx][newy] == 0) {
				visited[newx][newy] = 1;
				q.push({ newx, newy });
			}
		}
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1)
					bfs(i, j);
			}
		}

		cout << cnt << "\n";
		reset();
	}
}
#endif
//백준 : 7576번(토마토)
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
bool bripe = true;
int map[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
vector<int> v;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = curx + dx[i];
			int newy = cury + dy[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
			if (map[newx][newy] == 0 && visited[newx][newy] == 0) {
				visited[newx][newy] = 1;
				map[newx][newy] = map[curx][cury] + 1;
				v.push_back(map[newx][newy]);
				q.push({ newx, newy });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				bripe = false;
				break;
			}
		}
	}

	if (!bripe)
		cout << -1;
	else if (v.size() == 0)
		cout << 0;
	else {
		sort(v.begin(), v.end(), greater<int>());
		cout << v[0] - 1;
	}
}
#endif

//24.01.24
//백준 : 7562(나이트의 이동)
#if 0
#include <iostream>
#include <queue>
using namespace std;

int n, l;
int cur_x, cur_y;
int tar_x, tar_y;
int map[301][301];
int visited[301][301];
queue<pair<int, int>> q;

int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void reset() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == tar_x && b == tar_y) {
			cout << map[a][b] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++) {
			int new_a = a + dx[i];
			int new_b = b + dy[i];
			if (new_a < 0 || new_a >= l || new_b < 0 || new_b >= l) continue;
			if (visited[new_a][new_b] == 0) {
				q.push({ new_a, new_b });
				visited[new_a][new_b] = 1;
				map[new_a][new_b] = map[a][b] + 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l;
		cin >> cur_x >> cur_y;
		cin >> tar_x >> tar_y;

		bfs(cur_x, cur_y);
		reset();
	}
}
#endif

//24.01.16
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