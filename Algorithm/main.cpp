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
			// ���� ���
			if (m.find(table[i][j]) != m.end()) {
				if (table[i - 1][cnt] == table[i - 1][j]) cnt--;
				else
					it = m.find(table[i][j]);
				cnt = it->second;
				break;
			}
			// ���� ���
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
			// ���� ���
			if (m.find(table[i][j]) != m.end()) {
				if (table[i-1][cnt] == table[i-1][j]) cnt--;
				else 
				it = m.find(table[i][j]);
				cnt = it->second;
				break;
			}
			// ���� ���
			else {
				m.insert(make_pair(table[i][j], j));
			}
		}
	}

	table[r-1][j]

	if (cnt == 0) cout << 0;
	else cout << cnt-1;

	// ���� ������ ��(n) �˻�
	// ���� ���ڰ� ���� ���
		// �ش� ������ ���� ���� ���� ��
		// ���� ��� -> 3 �ݺ�
		// �ٸ� ��� -> �ش� ��(n) - 1
	// ���� ���ڰ� ���� ���
		// 0 ��ȯ
}
