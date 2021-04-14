#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	if (a[1] == b[1]) return a[0] < b[0];
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int n = routes.size();
	sort(routes.begin(), routes.end(), cmp);
	vector<bool> visited(n);
	
	int idx = 0;
	while (idx < n) {
		if (visited[idx]) {
			idx++;
			continue;
		}
		visited[idx] = true;
		answer += 1;
		int cutline = routes[idx][1];
		for (int i = idx + 1; i < n; i++) {
			if (routes[i][0] <= cutline) visited[i] = true;
		}
		idx++;
	}


	return answer;
}

// 이전에 짰던 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), cmp);
    int maxi = routes[0][1];
    int mini = routes[0][0];
    for(int i=1;i<routes.size();i++){
        if(maxi > routes[i][1]) maxi = routes[i][1];
        mini = routes[i][0];
        if(maxi < mini){
            answer+=1;
            mini = routes[i][0];
            maxi = routes[i][1];
        }
    }
    
    return answer;
}
