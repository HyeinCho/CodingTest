#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int answer = 0;
int inning[50][9];
int hitter[3];
vector<int> people(9);

// idx: 이닝 수, player: 몇번째 플레이어인지, out: 아웃횟수
void game(int idx, int player, int out, int total) {

	if (idx == n) {
		if (answer < total) answer = total;
		return;
	}

	int num = inning[idx][people[player]];
	if (num == 0) {
		if (out == 2) {
			for (int i = 0; i < 3; i++) hitter[i] = 0;
			game(idx + 1, (player + 1) % 9, 0, total);
		}
		else {
			game(idx, (player + 1) % 9, out + 1, total);
		}
	}
	else if (num == 1) {
		int tmp = hitter[2];
		for (int i = 2; i > 0; i--) {
			hitter[i] = hitter[i - 1];
		}
		hitter[0] = 1;
		game(idx, (player + 1) % 9, out, total + tmp);
	}
	else if (num == 2) {
		int tmp = hitter[2] + hitter[1];
		hitter[2] = hitter[0];
		hitter[1] = 1;
		hitter[0] = 0;
		game(idx, (player + 1) % 9, out, total + tmp);
	}
	else if (num == 3) {
		int tmp = hitter[2] + hitter[1] + hitter[0];
		hitter[2] = 1;
		for (int i = 1; i >= 0; i--) hitter[i] = 0;
		game(idx, (player + 1) % 9, out, total + tmp);
	}
	else if (num == 4) {
		int tmp = hitter[2] + hitter[1] + hitter[0] + 1;
		for (int i = 2; i >= 0; i--) hitter[i] = 0;
		game(idx, (player + 1) % 9, out, total + tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) cin >> inning[i][j];
	}

	for (int i = 0; i < 9; i++) people[i] = i;
	do {
		
		if (people[3] == 0) {
			game(0, 0, 0, 0);
			
		}
	} while (next_permutation(people.begin(), people.end()));

	cout << answer;
	return 0;
}
