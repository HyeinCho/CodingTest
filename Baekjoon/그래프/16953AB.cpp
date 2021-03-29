#include<iostream>
#include<string>

using namespace std;

long long a, b;
long long answer = 1000000001;

void calc(long long num, int cnt) {
	if (cnt > answer) return;

	if (num == b) {
		if (answer > cnt) answer = cnt;
		return;
	}
	else if (num > b) return;

	calc(num * 2, cnt + 1);
	calc(num * 10 + 1, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	calc(a, 0);
	
	if (answer == 1000000001) answer = -1;
	else answer++;

	cout << answer;

	return 0;
}
