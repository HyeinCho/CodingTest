// 크루스칼 알고리즘
// 모든 노드를 최대한 적은 비용으로 연결시키는 탐욕법

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cycle;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

// 부모 노드
int getParent(int x) {
    if (cycle[x] == x) return x;
    return cycle[x] = getParent(cycle[x]);
}

// 부모 병합
void unionParent(int x, int y) {
    int parent_x = getParent(x);
    int parent_y = getParent(y);

    if (parent_x < parent_y) cycle[parent_y] = parent_x;
    else cycle[parent_x] = parent_y;
}

// 같은 부모를 갖는지 여부
bool find(int x, int y) {
    int parent_x = getParent(x);
    int parent_y = getParent(y);

    if (parent_x == parent_y) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    cycle.resize(n);
    for (int i = 0; i < n; i++) cycle[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        int x = costs[i][0], y = costs[i][1], dist = costs[i][2];
        if (!find(x, y)) {
            unionParent(x, y);
            answer += dist;
        }
    }

    return answer;
}

int main() {
    int n = 5;
    //vector<vector<int>> costs = { {0, 1, 1}, { 0, 2, 2 }, { 1, 2, 5 }, { 1, 3, 1 }, { 2, 3, 8 } };
    vector<vector<int>> costs = { {0, 1, 1}, { 2, 3, 1 }, { 3, 4, 2 }, { 1, 2, 2 }, { 0, 4, 100 } };
    cout << solution(n, costs);
    return 0;
}
