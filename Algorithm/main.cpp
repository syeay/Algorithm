#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int>& A) {
	int n = A.size();
	if (n <= 2) return 0;

	vector<int> sumTile;
	sumTile.assign(n, 0);

	for (int i = 1; i < n; i++) {
		sumTile[i] = A[i] + A[i-1];
	}
	
	vector<int> map;
	map.assign(n, 0);
	map[1] = sumTile[1];

	for (int i = 2; i < n; i++) {
		map[i] = max(map[i-1], sumTile[i]);
		if (i >2)
			map[i] = max(map[i], map[i-3] + sumTile[i]);
	}

	int answer = map[n-1];
	for (int i = n - 1; i > 2; i--) {
		if (i >= 4)
			answer = max(answer, map[i-4] + sumTile[i]);
		answer = max(answer, map[i-2] + sumTile[i]);
	}
	
	for (int i = 0; i < map.size(); i++) {
		cout << map[i] << " ";
	}
	return answer;
}

int main() {
	vector<int> a = { 1, 2, 3, 3, 2 };
	solution(a);
}