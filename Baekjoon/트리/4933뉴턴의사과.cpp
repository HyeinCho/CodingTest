#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct node {
	char parent, left, right;

	node() {
		parent = left = right = '0';
	}
};

char makeTree(vector<node>& tree) {
	string s;
	stack<char> st;
	while (true)
	{
		cin >> s;
		if (s == "end") break;
		else if (s == "nil") {
			st.push('0');
		}
		else {
			st.push(s[0]);
		}

		if (st.size() >= 3 && st.top() != '0') {
			char cur = st.top();
			st.pop();
			char right = st.top();
			st.pop();
			char left = st.top();
			st.pop();
			tree[left].parent = cur;
			tree[right].parent = cur;
			st.push(cur);
		}
	}

	if (st.size() == 0) return 0;
	else return st.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		vector<node> tree1(91); // 대문자 Z가 90
		vector<node> tree2(91);
		char root1 = makeTree(tree1);
		char root2 = makeTree(tree2);

		bool answer = (root1 == root2);
		for (char c = 'A'; c <= 'Z'; c++) {
			if (tree1[c].parent != tree2[c].parent) {
				answer = false;
				break;
			}
		}
		
		if (answer) cout << "true" << '\n';
		else cout << "false" << '\n';
	}


	return 0;
}
