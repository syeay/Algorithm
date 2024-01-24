#include <iostream>
#include <queue>
using namespace std;

int n, l;
int cur_x, cur_y;
int tar_x, tar_y;
int map[301][301];
int visited[301][301];
queue<pair<int, int>> q;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void reset() {
	while(!q.empty()) q.pop();
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visited[i][j]= 0;
			map[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	q.push({x, y});
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
			if (new_a < 0 || new_a >= l || new_b <0 || new_b >= l) continue;
			if (visited[new_a][new_b] == 0) {
				q.push({new_a, new_b});
				visited[new_a][new_b] = 1;
				map[new_a][new_b] = map[a][b]+1;
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