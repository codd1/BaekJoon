// 2019 KAKAO BLIND RECRUITMENT > 오픈채팅방 (Level 1) - 0점
// https://school.programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    string temp;
    string type;
    string user_id;
    string user_name;
    map<string, string> user;

    string str;

    for (int i = 0; i < record.size(); i++) {
        cout << record[i] << endl;
    }

    int j = 0;
    for (int i = 0; i < record.size(); i++) {
        temp = record[i];

        for (; j < temp.length(); j++) {
            if (temp[j] != ' ') {
                type += temp[j];
            }
            else {
                break;
            }
        }

        for (j = j + 1; j < temp.length(); j++) {
            if (temp[j] != ' ') {
                user_id += temp[j];
            }
            else {
                break;
            }
        }

        for (j = j + 1; j < temp.length(); j++) {
            if (temp[j] != ' ') {
                user_name += temp[j];
            }
            else {
                break;
            }
        }

        if (type == "Enter") {
            str = "님이 들어왔습니다.";

            user.insert(make_pair(user_id, user_name));

            user_name.append(str);
            answer.push_back(user_name);
            //cout << answer << endl;
        }
        else if (type == "Leave") {
            str = "님이 나갔습니다.";
            user_name.append(str);
            user.erase(user_id);
            //cout << answer[i] << endl;
        }
        else if (type == "Change") {
            user[user_name] = user_name;
            auto it = find(answer.begin(), answer.end(), user_name);

            user_name.append(str);

            if (it != answer.end()) {
                answer.insert(it, user_name);
            }
        }


        j = 0;
        type = "";
        user_id = "";
        user_name = "";
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return answer;
}

int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(record);
}