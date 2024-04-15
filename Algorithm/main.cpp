#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> arr;
	int sum = 0;
	arr.push_back(0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		arr.push_back(sum);
	}

	// 벡터에 값을 넣어놓는다.
	//0 1 2 3 4 5
	//7 4 2 4 5
	//0 7 11 13 17 22

	if (k > sum) k = (sum*2-1) - k;

	for (int i = 1; i < arr.size(); i++) {
		if (k >= arr[i - 1] && k <= arr[i]) {
			cout << i;
			break;
		}

	}
}