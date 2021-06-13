#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent; // 사람, 부모
unordered_map<string, int> cost; // 사람, 수익

void divideCost(string person, int money) {
    if (person == "-") return;

    int tmp = money * 0.1;
    cost[person] += money - tmp;
    if (tmp < 1) return; // 1원 미만일 경우는 더 해도 소용없음
    divideCost(parent[person], tmp);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < referral.size(); i++) {
        parent[enroll[i]] = referral[i];
    }
    
    for (int i = 0; i < seller.size(); i++) {
        divideCost(seller[i], amount[i] * 100);
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(cost[enroll[i]]);
    }

    return answer;
}
