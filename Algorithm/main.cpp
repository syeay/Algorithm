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
		dfs(i+1, cnt+1);
		v.pop_back();
		visited[i] = 0;
	}
}	

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		map[i] = i+1;
	}

	dfs(0, 0);
}