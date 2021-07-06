#include<iostream>
#include<string>

using namespace std;

int maxi = 0, mini = 1000000000;

int oddCnt(int num) {
	int cnt = 0;
	while (num)
	{
		if ((num % 10) % 2) cnt++;
		num /= 10;
	}
	return cnt;
}

void splitNum(int num, int cnt) {
	if (num >= 0 && num < 10) { // 한 자리수
		if (maxi < cnt) maxi = cnt;
		if (mini > cnt) mini = cnt;
		return;
	}
	else if (num < 100) { // 두 자리수
		int sum = num / 10 + num % 10;
		splitNum(sum, cnt + oddCnt(sum));
	}
	else { // 세 자리수
		string s_num = to_string(num);
		int len = s_num.size();
		for (int i = 1; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				int sum = stoi(s_num.substr(0, i)) + stoi(s_num.substr(i, j - i)) + stoi(s_num.substr(j));
				splitNum(sum, cnt + oddCnt(sum));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	splitNum(n, oddCnt(n));
	cout << mini << ' ' << maxi;

	return 0;
}
