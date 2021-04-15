#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> inorder; // 중위
vector<int> postorder; // 후위
vector<int> tree; // 만들 트리

void divide(int in_front, int in_rear, int post_front, int post_rear) {
	if (post_front > post_rear) return;

	int parent = postorder[post_rear];
	cout << parent << ' ';

	int idx = find(inorder.begin(), inorder.end(), parent) - inorder.begin();
	
	/*
	4 2 7 5 8 1 6 3
	4 7 8 5 2 6 3 1

	4 2 7 5 8 / 1 / 6 3
	4 7 8 5 2 / 6 3 / 1

	4 / 2 / 7 5 8 / 1 / 6 3
	4 / 7 8 5 / 2 / 6 3 / 1

	4 / 2 / 7 / 5 / 8 / 1 / 6 3
	4 / 7 / 8 / 5 / 2 / 6 3 / 1

	post_order은 post_rear들이 부모노드
	inorder에서 해당 노드의 값을 가진 idx를 기준으로 양 옆을 나눔
	양옆을 나눈 갯수만큼 post_order도 양 옆을 나눔
	계속 진행
	*/
	divide(in_front, idx - 1, post_front, post_rear - (in_rear - idx + 1));
	divide(idx + 1, in_rear, post_rear - (in_rear - idx + 1) + 1, post_rear - 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	inorder.resize(n);
	postorder.resize(n);
	tree.resize(n);
	for (int i = 0; i < n; i++) cin >> inorder[i];
	for (int i = 0; i < n; i++) cin >> postorder[i];
	divide(0, n - 1, 0, n - 1);

	return 0;
}
