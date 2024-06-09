// ����/ť > �ùٸ� ��ȣ (Level 1) - 100��
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> n;

    for (int i = 0; i < s.length(); i++) {
        printf("%c\n", s[i]);
        if (!n.empty() && n.top() == '(' && s[i] == ')') {
            n.pop();
        }
        else {
            n.push(s[i]);
        }
    }

    if (!n.empty()) {
        answer = false;
    }

    printf("%d", answer);

    return answer;
}

int main() {
    // �Ʒ� �����Ϳ� ���� ��: 0(false)
    string s = "(()(";
    solution(s);
}