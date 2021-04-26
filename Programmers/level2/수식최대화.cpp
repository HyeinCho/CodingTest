// 이전 코드

#include <string>
#include <vector>
#include<deque>

using namespace std;

int priors[6][3] = { {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0} };
deque<long long> num;
deque<int> oper;

void splitExp(string expression) {	//expression 분리
	string tmp = "";
	for (char c : expression) {
		if (c == '*') {
			num.push_back(stoi(tmp));
			oper.push_back(0);
			tmp = "";
		}
		else if (c == '+') {
			num.push_back(stoi(tmp));
			oper.push_back(1);
			tmp = "";
		}
		else if (c == '-') {
			num.push_back(stoi(tmp));
			oper.push_back(2);
			tmp = "";
		}
		else {
			tmp += c;
		}
	}
	num.push_back(stoi(tmp));
}

long long calc(long long a, long long b, int op) {	//계산
	if (op == 0) return a * b;
	if (op == 1) return a + b;
	if (op == 2) return a - b;
}

long long solution(string expression) {
	long long answer = 0;
	
	splitExp(expression);
	
	for (int i = 0;i < 6;i++) {
		deque<long long> _num = num;
		deque<int> _oper = oper;

		for (int j = 0;j < 3;j++) {	//우선순위대로 계산
			deque<long long> tmp_num;
			deque<int> tmp_op;
			tmp_num.push_back(_num[0]);
			
			int size = _oper.size();
			for (int k = 0;k < size;k++) {
				tmp_num.push_back(_num[k + 1]);
				tmp_op.push_back(_oper[k]);
				if (priors[i][j] == tmp_op.back()) {	//우선순위에 맞는 부호가 있으면
					long long n2 = tmp_num.back();
					tmp_num.pop_back();
					long long n1 = tmp_num.back();
					tmp_num.pop_back();
					int op = tmp_op.back();
					tmp_op.pop_back();

					tmp_num.push_back(calc(n1, n2, op));
				}
			}
			_num = tmp_num;
			_oper = tmp_op;
		}
		if (_num.front() < 0) _num.front() = -_num.front();	//절댓값
		if (answer < _num.front()) answer = _num.front();
	}
	return answer;
}
