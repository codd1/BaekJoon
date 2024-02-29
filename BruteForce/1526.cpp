#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int result = 4;

	cin >> N;

	string strB = to_string(N);
	string strI;
	bool flag;		// strI에서 앞자리에 4 또는 7이 포함되어있는지 체크하기 위함

	for (int i = 4; i<=N; i++) {
		strI = to_string(i);
		flag = true;

		for (int j = 0; j < strI.length(); j++) {
			if (strI[j] == '4' || strI[j] == '7' && flag==true) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			result = i;
		}
		
	}

	cout << result << endl;

	return 0;
}