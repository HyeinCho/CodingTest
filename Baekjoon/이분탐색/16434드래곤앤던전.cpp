#include<iostream>
#define MAX 123456000000000000
using namespace std;

int n, atk;
long long answer = -1;
int info[123456][3];

void binarySearch(long long front, long long rear) {
	if (front > rear) return;
	long long mid = (front + rear) / 2; // 최대 생명력
	long long cur_atk = atk; // 현재 공격력
	long long cur_hp = mid; // 현재 생명력

	for (int i = 0; i < n; i++) {
		if (info[i][0] == 1) {
			long long monster_atk = info[i][1]; // 몬스터 공격력
			long long monster_hp = info[i][2]; // 몬스터 생명력

			// 사람이 몬스터를 공격하는 횟수 > 몬스터가 사람을 공격하는 횟수
			// 사람이 죽음
			if ((monster_hp - 1) / cur_atk > (cur_hp - 1) / monster_atk) {
				binarySearch(mid + 1, rear);
				return;
			}
			// 사람이 몬스터 공격하는 횟수 * 몬스터한테 받은 공격
			// 사람의 공격력 = 몬스터의 hp인 경우
			// 사람은 공격받지 않았기 때문에 -1을 해줘야흔다
			cur_hp -= (monster_hp - 1) / cur_atk * monster_atk;

		}
		else {
			cur_atk += info[i][1];
			cur_hp += info[i][2];
			if (cur_hp > mid) cur_hp = mid;
		}
	}

	// 라운드 완료
	if (answer > mid || answer == -1) answer = mid;
	binarySearch(front, mid - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> atk;
	for (int i = 0; i < n; i++) {
		cin >> info[i][0] >> info[i][1] >> info[i][2];
	}

	long long front = 1;
	long long rear = MAX;
	binarySearch(front, rear);

	cout << answer;
	return 0;
}
