#include <string>
#include <vector>
#include<algorithm>
#include <map>

using namespace std;

vector<string> makeInfo(1);
map<string, vector<int>> m;

// info 쪼개기
vector<string> splitInfo(string s) {
    vector<string> people;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            people.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    people.push_back(tmp);
    return people;
}

void dfs(string s, int cnt) {
    if (cnt == 4) {
        string tmp = s.substr(0, s.size() - 3);
        m[tmp].push_back(stoi(makeInfo[4]));
        return;
    }

    dfs(s + makeInfo[cnt] + "and", cnt + 1);
    dfs(s + "-and", cnt + 1);
}

// query 쪼개기
pair<string, int> score(string s) {
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            return { tmp, stoi(s.substr(i)) };
        }
        else if (s[i] == ' ') continue;
        else {
            tmp += s[i];
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);

    // info 순회하면서 문자열 파싱 -> 모든 경우의 수(16가지)를 map에 넣는다
    // 이 때, map의 key는 16가지 경우의 문자열, value는 그 문자열에 해당하는 값
    for (int i = 0; i < info.size(); i++) {
        makeInfo = splitInfo(info[i]);
        dfs("", 0);
    }

    // map의 value들을 오름차순 정렬 (미리 안하면 시간초과...!)
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    // query 순회하면서 문자열 파싱
    // map에 해당 query가 있는지 보고 그 값이상인 애들의 개수를 찾기
    for (int i = 0; i < query.size(); i++) {
        pair<string, int> q = score(query[i]);

        if (m.find(q.first) != m.end()) {
            int front = 0;
            int rear = m[q.first].size() - 1;
            while (front <= rear) {
                int mid = (front + rear) / 2;
                if (m[q.first][mid] < q.second) {
                    front = mid + 1;
                }
                else {
                    rear = mid - 1;
                }
            }
            answer[i] = m[q.first].size() - front;
        }

    }

    return answer;
}
