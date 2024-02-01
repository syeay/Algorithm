#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� n ������ �� m
long long n, m;
// ��� ���� �迭
vector<long long> path;
// ���� �� ���Ժ� ���� �� 2���� �迭
vector<vector<long long>> fare;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fare.assign(n+1, vector<long long>());
	path.assign(m, 0);

	for (long long i = 0; i < m; i++) {
		// i�� ° �̵��ϴ� ����
		long long a;
		cin >> a;
		path[i] = a;
	}

	for (long long i = 1; i < n; i++) {
		// i�� Ƽ�� ���Ժ�, ī�� ����, ī�� ���ź�
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
			// �ڽ��� ������ a���� ���θ� ����
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