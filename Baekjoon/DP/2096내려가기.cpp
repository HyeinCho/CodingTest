#include<iostream>
#include<algorithm>

using namespace std;

int n;
int maxi[3], tmp1[3];
int mini[3], tmp2[3];
int arr[100000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];	
		}
	}

	for (int j = 0; j < 3; j++) {
		maxi[j] = mini[j] = arr[0][j];
	}

	for (int i = 1; i < n; i++) {
		tmp1[0] = arr[i][0] + max(maxi[0], maxi[1]);
		tmp2[0] = arr[i][0] + min(mini[0], mini[1]);

		tmp1[1] = arr[i][1] + *max_element(maxi, maxi + 3);
		tmp2[1] = arr[i][1] + *min_element(mini, mini + 3);

		tmp1[2] = arr[i][2] + max(maxi[2], maxi[1]);
		tmp2[2] = arr[i][2] + min(mini[2], mini[1]);

		for (int j = 0; j < 3; j++) {
			maxi[j] = tmp1[j];
			mini[j] = tmp2[j];
		}
	}

	cout << *max_element(maxi, maxi + 3) << ' ' << *min_element(mini, mini + 3);

	return 0;
}
