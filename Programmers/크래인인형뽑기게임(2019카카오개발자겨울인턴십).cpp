 // 2019 īī�� ������ �ܿ� ���Ͻ� > ũ���� �����̱� ���� (Level 1) - 36.4��
 // https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<vector<int>> board2 = board;
    stack<int> result;

    int prev_result = 0;

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (!result.empty() && (result.top() == board[j][moves[i] - 1])) {
                    result.pop();
                    answer += 2;
                    board[j][moves[i] - 1] = 0;       // �� �ڵ� ���Ծ ����...

                    break;
                }
                else {
                    if (!result.empty()) {
                        prev_result = result.top();
                    }
                    result.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;

                    break;
                }
            }
        }
    }

    printf("%d", answer);

    return answer;
}

int main() {
    // �Ʒ� �����Ϳ� ���� ����: 4
    vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    solution(board, moves);

    return 0;
}