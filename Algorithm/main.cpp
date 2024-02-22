#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[301][301];
int psum[301][301];

void Solve() {
	int answer = -1001;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i-k<0 || j-k<0) break;
				else {
					answer = max(answer, psum[i][j]-psum[i-k][j]-psum[i][j-k]+psum[i-k][j-k]);
				}
			}
		}
	}
	cout << answer;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {			
			cin >> arr[i][j];
			psum[i][j] = psum[i][j-1]+psum[i-1][j]+arr[i][j]-psum[i-1][j-1];
		}
	}

	Solve();
}