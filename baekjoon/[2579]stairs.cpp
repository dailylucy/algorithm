#include <iostream>
using namespace std;

int scores[301] = { 0 };  
int route[302] = { 0 }; 


void dp(int n,int last) {
	if (n == 0) { route[n] = 0; dp(n+1, last); return; }
	if (n == 1) { route[n] = scores[n]; dp(n+1, last); return; }
	if (n == 2) { route[n] = scores[n] + scores[n - 1]; dp(n + 1, last); return; }
	if (n <= last) {		
		// n > 3 경우
		// (1) route[n-2] + scores[n]
		// (2) route[n-3] + scores[n-1] + scores[n]
		// 둘 중 더 큰 값을 route[n]에 assign
		int tmp1 = route[n - 2] + scores[n];
		int tmp2 = route[n - 3] + scores[n - 1] + scores[n];
		route[n] = tmp1 > tmp2 ? tmp1 : tmp2;
		dp(n + 1, last);
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> scores[i];
	}

	dp(0, N);

	cout << route[N] << endl;
	return 0;
}
