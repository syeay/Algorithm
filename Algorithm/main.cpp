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
	if (n==1 && m==1) {
		cout << 1;
		return 0;
	}

	q.push(Road(0,0,1));
	visited[0][0][1] = 1;
	bfs();

	// ¶ÕÁö ¾Ê¾ÒÀ» ¶§
	int a = visited[n-1][m-1][1];
	// ¶Õ¾úÀ» ¶§
	int b = visited[n-1][m-1][0];
	if (a == 0 && b == 0) cout << -1;
	else {
		if (a == 0) cout << b;
		else if (b == 0) cout << a;
		else if (b <= a) cout << b;
		else cout << a;
	}
}