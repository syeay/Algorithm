#include <iostream>
#include <cmath>

using namespace std;

int n, k;
long long cnt = 0;
int psum[200001];
map

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		psum[i] = psum[i-1] + a;
	}

	for (int i = 0; i < n; i++) {
		int answer = 0;
		for (int j = i; j < n; j++) {
			// i~j������ �������� k�� ���
			// i������ ������ - k = j������ ������
			answer += 
			if (psum[i]- k == psum[j]) cnt++;
		}
	}

	

	cout << cnt;
}