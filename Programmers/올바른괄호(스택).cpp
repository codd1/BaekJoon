// 스택/큐 > 올바른 괄호 (Level 1) - 100점
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
    // 아래 데이터에 대한 답: 0(false)
    string s = "(()(";
    solution(s);
}