#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ¼öÀÇ °¹¼ö
	cin >> N;

	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < N; i++) {
		cout << num[i] << endl;
	}
	
	return 0;
}