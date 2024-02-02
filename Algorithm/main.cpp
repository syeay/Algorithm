#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r, c;
int cnt=0;
string table[1001][1001];
map<string, int> m;
map<string, int>::iterator it;

void recur() {
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			// 있을 경우
			if (m.find(table[i][j]) != m.end()) {
				if (table[i - 1][cnt] == table[i - 1][j]) cnt--;
				else
					it = m.find(table[i][j]);
				cnt = it->second;
				break;
			}
			// 없을 경우
			else {
				m.insert(make_pair(table[i][j], j));
			}
		}
	}
}

int main() {
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char a;
			cin >> a;
			table[i][j] = a;
		}
	}

	//cout << table[0][1];


	for (int i = r-1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			// 있을 경우
			if (m.find(table[i][j]) != m.end()) {
				if (table[i-1][cnt] == table[i-1][j]) cnt--;
				else 
				it = m.find(table[i][j]);
				cnt = it->second;
				break;
			}
			// 없을 경우
			else {
				m.insert(make_pair(table[i][j], j));
			}
		}
	}

	table[r-1][j]

	if (cnt == 0) cout << 0;
	else cout << cnt-1;

	// 가장 마지막 행(n) 검사
	// 같은 문자가 있을 경우
		// 해당 문자의 위의 행의 글자 비교
		// 같을 경우 -> 3 반복
		// 다를 경우 -> 해당 행(n) - 1
	// 같은 문자가 없을 경우
		// 0 반환
}
