#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end()); // 들어온 시간 순으로 정렬
    priority_queue < vector<int>, vector<vector<int>>, cmp> pq; // 작업시간이 작은 순

    int idx = 0;
    int time = 0; // 현재 시간
    while (idx < jobs.size() || !pq.empty()) {
        // 현재 시간이 jobs의 작업 시작 시간보다 크거나 같으면
        // 큐에 넣어 대기작업
        if (idx < jobs.size() && time >= jobs[idx][0]) { 
            pq.push(jobs[idx]);
            idx++;
            continue;
        }

        if (!pq.empty()) { // 대기하는 애들 중 가장 작업 시간이 짧은 애
            time += pq.top()[1]; // 다음 시간 =  현재 시간(time) + 소요 시간
            answer += time - pq.top()[0]; // 소요한 시간: (다음 시간 - 시작시간)
            pq.pop();
        }
        else {
            time = jobs[idx][0]; // 다음에 갈 시간
        }
    }


    return answer / jobs.size();
}
