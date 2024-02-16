#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    for (int i = 0; i < 100; i++) {
        getline(cin, str);      // 공백을 포함한 입력을 받을 때 getline 함수 활용

        cout << str << endl;
    }

    return 0;
}