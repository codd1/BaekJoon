#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int N = 0;

	scanf("%d", &N);			// ����� ���ؿ��� scanf_s ��� �� ������ ���� �߻�!
								// scanf_s�� VS���� �����ϴ� ������, ǥ���� �ƴ�.

	// cpp�� cin�� cout�� ����� ��� "�ð� �ʰ�" ������ ���� ������ �־���.
	// C�� scanf�� printf�� �ξ� �����Ƿ� cstdio ����� ����� �ذ��ϱ�!
	for (int i = 1; i <= N; i++) {
		printf("%d\n", i);
	}

	return 0;
}