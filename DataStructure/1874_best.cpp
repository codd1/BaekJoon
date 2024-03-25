#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		// ������ ����
	int num[100001] = { 0 };		// n���� ���� ����
	int result[100001] = { 0 };		// ��� ����
	string str;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	int temp = 1;	// ���ÿ� push�ϴ� �ڿ��� (1���� ��������)
	int numIndex = 1;
	stack<int> stack;

	while (numIndex <= n) {
		if (temp <= num[numIndex]) {		// �������� �ڿ��� <= ���� ���� ��
			for (int i = temp; i <= num[numIndex]; i++, temp++) {		// �������� �ڿ��� == ���� ���� ������ �ݺ�
				stack.push(i);
				str += "+\n";
				//printf("temp = %d, stack.push(%d)\t\t\t\tnumIndex = %d\n", temp, i, numIndex);

				if (i == num[numIndex]) {	// �������� pop
					stack.pop();
					str += "-\n";
					//printf("i == num[%d] --> stack.pop()\t\t\t\tnumIndex = %d\n", numIndex, numIndex);
					numIndex++;
					temp++;
					break;
				}
			}
		}
		else {			// �������� �ڿ��� > ���� ���� ��
			if ((stack.top()) > num[numIndex]) {
				str = "NO\n";
				break;
			}
			else {
				stack.pop();
				str += "-\n";
				//printf("stack.top(=%d) == num[%d] --> stack.pop()\tnumIndex = %d\n", stack.top(), numIndex, numIndex);
				numIndex++;
				//temp++;
			}
		}
	}

	cout << str << endl;

	return 0;
}