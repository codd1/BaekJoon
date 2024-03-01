#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int count = 0;

	cin >> N;
	
	string strI;

	for (int i = 1; i <= N; i++) {
		if (i <= 99) {
			count++;
		}
		else if (i == 1000) {
			break;
		}
		else {
			strI = to_string(i);

			for (int j = 0; j < strI.length() - 2; j++) {
				if (strI[j] - strI[j + 1] == strI[j + 1] - strI[j + 2]) {
					count++;
				}
			}
		}
		
	}

	cout << count << endl;

	return 0;
}