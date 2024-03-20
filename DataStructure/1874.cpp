#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int num[100000] = { 0, };
	int stack[100000] = { 0, };
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int now = 1;
	int numIndex = 0;
	int stackIndex = 0;
	
	while (numIndex < n) {
		// Stack¿¡ push
		if (stackIndex >= 0 && stack[stackIndex] == 0) {
			str += "+\n";
			stack[stackIndex] = now;
			now++;
		}

		// Stack¿¡¼­ pop
		if (stack[stackIndex] == num[numIndex]) {
			str += "-\n";
			stack[stackIndex] = 0;
			stackIndex--;
			numIndex++;
			continue;
		}

		stackIndex++;
		if (now > n && stackIndex == 100000) {
			str = "NO";
			break;
		}
	}

	cout << str << endl;

	return 0;
}