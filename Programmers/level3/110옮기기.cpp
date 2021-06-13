#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (string tmp : s) {
        string str = "";
        int cnt = 0;
        for (int i = 0; i < tmp.size(); i++) {
            str += tmp[i];
            if (str.size() >= 3 && str.substr(str.size() - 3, 3) == "110") {
                cnt++;
                for (int j = 0; j < 3; j++) str.pop_back();
            }
        }
        
        int idx = str.find_last_of('0');
        string result = "";
        if (idx == -1) {
            while (cnt--)
            {
                result += "110";
            }
            result += str;
        }
        else {
            result = str.substr(0, idx + 1);
            while (cnt--) {
                result += "110";
            }
            result += str.substr(idx + 1);
        }
        answer.push_back(result);
    }
    return answer;
}
