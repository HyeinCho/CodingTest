#include<iostream>
#include<algorithm>

using namespace std;

int n;
int liquid[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> liquid[i];
	sort(liquid, liquid + n);

	int front = 0;
	int rear = n - 1;
	int answer = 2000000001;
	pair<int, int> p;
	while (front < rear && front < n && rear >= 0) {
		int sum = liquid[front] + liquid[rear] ;
		if (sum < 0) {
			if (-sum < answer) {
				answer = -sum;
				p = { liquid[front], liquid[rear] };
			}
			front++;
		}
		else if (sum > 0) {
			if (sum < answer) {
				answer = sum;
				p = { liquid[front], liquid[rear] };
			}
			rear--;
		}
		else {
			p = { liquid[front], liquid[rear] };
			break;
		}
	}
	cout << p.first << ' ' << p.second;

	return 0;
}
