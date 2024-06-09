// 연습 문제 > 추억 점수 (Level 1) - 100점
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size(), 0);

    for (int i = 0; i < photo.size(); i++) {
        for (int j = 0; j < photo[i].size(); j++) {
            for (int k = 0; k < name.size(); k++) {
                if ((photo[i][j].compare(name[k])) == 0) {
                    answer[i] += yearning[k];
                    //printf("%d. answer = %d\n", i, answer[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }

    return answer;
}

int main() {
    // 아래 데이터에 대한 정답: [5, 15, 0]
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5, 10, 1, 3 };
    vector<vector<string>> photo = { {"may"}, {"kein", "deny", "may"}, {"kon", "coni"} };

    solution(name, yearning, photo);
}