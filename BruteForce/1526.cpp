#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int result = 4;

	cin >> N;

	string strB = to_string(N);
	string strI;
	bool flag;		// strI���� ���ڸ��� 4 �Ǵ� 7�� ���ԵǾ��ִ��� üũ�ϱ� ����

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