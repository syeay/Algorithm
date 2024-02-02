//24.02.02
//백준 : 11656번(접미사 배열)
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	string str;
	cin >> str;

	vector<string> v;
	//v.assign(str.length()+1, "");

	for (int i = 0; i < str.length(); i++) {
		string newstr;
		for (int j = i; j < str.length(); j++) {
			newstr += str[j];
		}
		v.push_back(newstr);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
#endif // 0


//24.02.01
//백준 : 10713번(기차여행)
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 도시 n 여행일 수 m
long long n, m;
// 경로 도시 배열
vector<long long> path;
// 도로 별 구입비 등이 들어간 2차원 배열
vector<vector<long long>> fare;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fare.assign(n + 1, vector<long long>());
	path.assign(m, 0);

	for (long long i = 0; i < m; i++) {
		// i일 째 이동하는 도시
		long long a;
		cin >> a;
		path[i] = a;
	}

	for (long long i = 1; i < n; i++) {
		// i의 티켓 구입비, 카드 사용비, 카드 구매비
		long long a, b, c;
		cin >> a >> b >> c;
		fare[i].push_back(a);
		fare[i].push_back(b);
		fare[i].push_back(c);
		fare[i].push_back(0);
	}

	for (long long i = 1; i < m; i++) {
		long long a = path[i - 1];
		long long b = path[i];
		if (a < b) {
			// 자신을 포함해 a개의 도로를 지남
			while (b != a) {
				fare[a][3]++;
				a++;
			}
		}
		else {
			while (b != a) {
				fare[b][3]++;
				b++;
			}
		}
	}

	long long answer = 0;
	for (long long i = 1; i < n; i++) {
		if (fare[i][3] != 0) {
			long long a = fare[i][3] * fare[i][0];
			long long b = fare[i][3] * fare[i][1] + fare[i][2];

			if (a <= b)
				answer += a;
			else
				answer += b;
		}
	}

	cout << answer;
}
#endif // 0


//24.01.31
//백준 : 22868번(산책)
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s, e;
int cnt1, cnt2;
vector<vector<int>> vec;
int visited[10001];
int check[10001];
queue<pair<int, int>> q;

void reset() {
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	int a = check[e];

	while (1) {
		visited[a] = 1;
		a = check[a];
		if (a == 0) break;
	}
}

int bfs(int a, int b) {
	visited[a] = 1;
	q.push({ a, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];
			if (!visited[next]) {
				visited[next] = 1;
				check[next] = cur;
				q.push(make_pair(next, cnt + 1));
			}
			if (next == b)
				return cnt + 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vec.assign(n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cin >> s >> e;

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	int a = bfs(s, e);
	reset();
	int b = bfs(e, s);

	cout << a + b;
	return 0;
}

#endif // 0

//24.01.29
//백준 : 15649번(N과 M _1)
#if 0
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[9];
int visited[9];
vector<int> v;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		v.push_back(map[i]);
		dfs(cnt + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		map[i] = i + 1;
	}

	dfs(0);

	return 0;
}
#endif // 0
//백준 : 15650번(N과 M _2)
#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[9];
int visited[9];
vector<int> v;
queue<int> q;

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = num; i < n; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		v.push_back(map[i]);
		dfs(i + 1, cnt + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		map[i] = i + 1;
	}

	dfs(0, 0);
}
#endif // 0

//24.01.28
//백준 : 11478번(서로 다른 부분 문자열의 개수)
#if 0
#include <iostream>
#include <string>
#include <unordered_set>
//#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//clock_t start, finish;
	//double duration;
	//start = clock();
	string str;
	unordered_set<string> s;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string tmp = { str[i] };
		for (int j = i; j < str.size(); j++) {
			s.insert(tmp);
			tmp += str[j + 1];
			//s.insert(str.substr(j, i));
		}
	}

	cout << s.size();
	//finish = clock();
	//duration = (double)(finish - start);
	//cout << duration << "초" << endl;
}
#endif
//시간 계산 코드
#if 0
#include <ctime>
clock_t start, finish;
double duration;
start = clock();
finish = clock();
duration = (double)(finish - start);
cout << duration << "ms초" << endl;
#endif // 0

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
//백준 : 2206번(벽 부수고 이동하기)
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };


struct Road
{
	int x, y, op;
	Road(int a, int b, int c) {
		x = a; y = b; op = c;
	}
};

queue<Road> q;

void bfs() {
	while (!q.empty()) {
		int a = q.front().x;
		int b = q.front().y;
		int op = q.front().op;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (na < 0 || nb < 0 || na >= n || nb >= m) continue;
			if (op == 1) {
				if (visited[na][nb][1] == 0 && map[na][nb] == 0) {
					visited[na][nb][1] = visited[a][b][1] + 1;
					q.push(Road(na, nb, 1));
				}
				else if (visited[na][nb][1] == 0 && map[na][nb] == 1) {
					visited[na][nb][0] = visited[a][b][1] + 1;
					q.push(Road(na, nb, 0));
				}
			}
			else {
				if (visited[na][nb][0] == 0 && map[na][nb] == 0) {
					visited[na][nb][0] = visited[a][b][0] + 1;
					q.push(Road(na, nb, 0));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}

	q.push(Road(0, 0, 1));
	visited[0][0][1] = 1;
	bfs();

	// 뚫지 않았을 때
	int a = visited[n - 1][m - 1][1];
	// 뚫었을 때
	int b = visited[n - 1][m - 1][0];
	if (a == 0 && b == 0) cout << -1;
	else {
		if (a == 0) cout << b;
		else if (b == 0) cout << a;
		else if (b <= a) cout << b;
		else cout << a;
	}
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