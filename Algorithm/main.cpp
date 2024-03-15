#include <iostream>
#include <string>
#include <vector>
//#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int>  v;
	v.assign(7, 0);
	int cnt = 0;

	for (int i = 0; i < 24; i++) {
		string a;
		cin >> a;
		if (a != "")
			cnt++;
		if (a == "Re") {
			v[0] += 1;
		}
		else if (a == "Pt") {
			v[1] += 1;
		}
		else if (a == "Cc") {
			v[2] += 1;
		}
		else if (a == "Ea") {
			v[3] += 1;
		}
		else if (a == "Tb") {
			v[4] += 1;
		}
		else if (a == "Cm") {
			v[5] += 1;
		}
		else if (a == "Ex") {
			v[6] += 1;
		}
		else
			continue;
	}

	cout << fixed;
	cout.precision(2);
	cout << "Re " << v[0] << " " << v[0] / (double)cnt << "\n";
	cout << "Pt " << v[1] << " " << v[1] / (double)cnt << "\n";
	cout << "Cc " << v[2] << " " << v[2] / (double)cnt << "\n";
	cout << "Ea " << v[3] << " " << v[3] / (double)cnt << "\n";
	cout << "Tb " << v[4] << " " << v[4] / (double)cnt << "\n";
	cout << "Cm " << v[5] << " " << v[5] / (double)cnt << "\n";
	cout << "Ex " << v[6] << " " << v[6] / (double)cnt << "\n";
	cout << "Total " << cnt << " 1.00";
}