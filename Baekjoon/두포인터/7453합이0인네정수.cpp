#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
long long A[4000];
long long B[4000];
long long C[4000];
long long D[4000];
vector<long long> AB;
vector<long long> CD;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	// A, B의 합 / C, D의 합
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());

	// AB + CD가 0인거 찾기
	// AB = -CD

	// lower_bound : 찾으려는 값보다 같거나 큰 숫자가 언제 처음 등장하는지
	// upper_bound : 찾으려는 값을 초과하는 숫자가 언제 처음 등장하는지
	// 1 2 2 3 4   num: 2
	// lower_bound : 1
	// upper_bound : 3
	// num의 갯수: upper_bound - lower_bound 
	long long answer = 0;
	for (int i = 0; i < CD.size(); i++) {
		long long num = CD[i];
		long long cnt = upper_bound(AB.begin(), AB.end(), -num) - lower_bound(AB.begin(), AB.end(), -num);
		answer += cnt;
	}

	cout << answer;

	return 0;
}
