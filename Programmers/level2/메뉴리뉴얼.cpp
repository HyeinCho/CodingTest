#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(string s, vector<string> orders) {
    int result = 0;
    for (int i = 0; i < orders.size(); i++) {
        string word = orders[i];
        int cnt = 0;
        if(word.size() < s.size()) continue;
        else if(word.size() == s.size()){
            sort(word.begin(), word.end());
            if(word == s) result++;
            continue;
        }
        for (int j = 0; j < s.size(); j++) {
            for (int k = 0; k < word.size(); k++) {
                if (s[j] == word[k]) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == s.size()) {
            result++;
        }
    }
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> alpha(26);
    for (int i = 0; i < 26; i++) alpha[i] = i + 'A';

    vector<int> v(26);
    for (int i = 0; i < course.size(); i++) {
        int num = course[i];
        for (int j = 0; j < num; j++) v[j] = 0;
        for (int j = num; j < 26; j++) v[j] = 1;

        vector<string> tmp;
        int maxi = 0;
        do {
            string s = "";
            for (int j = 0; j < 26; j++) {
                if (v[j] == 0) {
                    s += alpha[j];
                    if (s.size() == num) break;
                }
            }
            int total = check(s, orders);
            if (total > 1) {
                if (maxi < total) {
                    tmp.clear();
                    tmp.push_back(s);
                    maxi = total;
                }
                else if (maxi == total) {
                    tmp.push_back(s);
                }
            }

        } while (next_permutation(v.begin(), v.end()));

        for (string str : tmp) answer.push_back(str);
    }

    sort(answer.begin(), answer.end());
    return answer;
}
