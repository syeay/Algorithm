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

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

void bfs() {
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = a+dx[i];
			int nb = b+dy[i];
			int nc = c+dz[i];

			if (na<0 || nb<0 || nc<0 || na>=h || nb>=n || nc>=m) continue;
			if (map[na][nb][nc] == 0 && visited[na][nb][nc] == 0) {
				visited[na][nb][nc] = 1;
				q.push({na, nb, nc});
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
					q.push({i, j, k});
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
		cout << v[0]-1;
	}

	return 0;
}