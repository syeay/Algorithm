#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result=0, result_cnt=0;
// �� �� �� �Ʒ�
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> v;
vector<int> result_vec;
vector<vector<int>> visited;

void input() {
	cin >> n;
	v.assign(n, vector<int>(n));
	visited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		// �� ���� �Է��� string���� �ޱ�
		string arr;
		cin >> arr;
		for (int j = 0; j < arr.length(); j++) {
			// ���ڴ� '' ���ڿ��� ���� ""
			if(arr[j] == '1')
				v[i][j] = 1;
			else 
				v[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		// �������� �߽����� �������� üũ
		int nx = x+dx[i];
		int ny = y+dy[i];

		// ������ ���� 2���� �迭�� ��� ���
 		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		
		// ����Ʈ�� �ְ� �湮���� �ʾ��� ���
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
				// ù ������ �湮 true
				visited[i][j] = 1;
				result_cnt = 1;
				dfs(i, j);
				result_vec.push_back(result_cnt);
				result++;
			}
		}
	}
	// �������� ����
	sort(result_vec.begin(), result_vec.end());
	cout << result << "\n";
	for (int i = 0; i < result_vec.size(); i++) {
		cout << result_vec[i] <<"\n";
	}
	return 0;
}