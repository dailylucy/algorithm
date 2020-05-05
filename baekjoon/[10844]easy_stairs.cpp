// 알고리즘 문제 url
// https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;
#define MOD 1000000000
typedef long long ll;
ll d[101][10] = { 0 };

ll dp(int n, int cur) {
	if (cur > 9 || cur < 0) return 0;

	if (n == 1) {
		if (cur) return d[n][cur] = 1;
		else	 return d[n][cur] = 0;
	}

	if (d[n][cur]) return d[n][cur];

	// 0일 경우, 9일 경우 
	// n-1에서 1인거, 8인거 몇 개인지 확인
	if (cur == 0) return d[n][cur] = dp(n - 1, cur + 1) % MOD;
	if (cur == 9) return d[n][cur] = dp(n - 1, cur - 1) % MOD;

	// 1~8인 경우
  // n-1에서 cur-1, cur+1 확인
	if (d[n - 1][cur - 1]) d[n][cur] = (d[n][cur] + d[n - 1][cur - 1]) % MOD;
	else				           d[n][cur] = (d[n][cur] + dp(n - 1, cur - 1)) % MOD;
	if (d[n - 1][cur + 1]) d[n][cur] = (d[n][cur] + d[n - 1][cur + 1]) % MOD;
	else				           d[n][cur] = (d[n][cur] + dp(n - 1, cur + 1)) % MOD;
	
	return d[n][cur];
}

int main() {
	int N;
	cin >> N;
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp(N, i)) % MOD;
	}
		
	cout << sum << endl;
	return 0;
}
