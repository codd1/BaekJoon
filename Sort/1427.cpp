#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;	// N�� string���� �Ѳ����� �Է¹ް�,
	cin >> N;

	vector<char> num;

	char input;

	for (int i = 0; i < N.length(); i++) {
		input = N[i];

		if (input == '\n') {
			break;
		}

		num.push_back(input);	// '\n'�� ���� ������ vector�� ����
	}

	int maxIndex;

	int index = 0;
	int temp = 0;
	while (index < num.size()) {
		maxIndex = max_element(num.begin() + index, num.end()) - num.begin();	// �ִ��� ��� iter ����

		// �ִ񰪰� �� �� �ε����� ��ġ�� �ٲ�.
		temp = num[maxIndex];
		num[maxIndex] = num[index];
		num[index] = temp;

		index++;
	}

	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
	}

	return 0;
}