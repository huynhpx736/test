#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int test;
	cin >> test;
	while (test--) {
		vector<int>a;
		int n=0;
		cin >> n;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		int min = 10000000;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] < min) min = a[i] - a[i - 1];
		}
		cout << min << endl;
	}
	return 0;
}

