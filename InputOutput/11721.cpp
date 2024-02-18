#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "";
	int line = 1;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		if (i == ((line * 10) - 1)) {
			cout << endl;
			line++;
		}
	}

	return 0;
}