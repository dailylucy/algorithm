#include <iostream>
using namespace std;

int cases[1001] = { 0 };

int dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (cases[n]) return cases[n];
	return cases[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main() {
	int N;
	cin >> N;
	cout << dp(N) << endl;
	return 0;
}
