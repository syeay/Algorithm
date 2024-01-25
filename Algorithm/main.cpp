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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs() {
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = curx + dx[i];
			int newy = cury + dy[i];
			if (newx<0 || newy<0 || newx>=n || newy>=m) continue;
			if (map[newx][newy] == 0 && visited[newx][newy] == 0) {
				visited[newx][newy] = 1;
				map[newx][newy] = map[curx][cury] + 1;
				v.push_back(map[newx][newy]);
				q.push({newx, newy});
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
				q.push({i, j});
				visited[i][j] = 1;
			}			
		}
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0){
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