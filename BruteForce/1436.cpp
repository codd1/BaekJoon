#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int count = 0;		// '666'ÀÌ ³ª¿Â È½¼ö

	string str;

	cin >> N;

	int i = 666;

	while (1) {
		str = to_string(i);
		for (int j = 0; j < str.length() - 2; j++) {
			if (str[j] == '6' && str[j + 1] == '6' && str[j + 2] == '6') {
				count++;
				if (count == N) {
					cout << i << endl;
					return 0;
				}
				break;
			}
		}
		i++;
	}
}