
#include<algorithm>
#include<iostream>
#define TIMEMAX 1000000000LL
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long M, N;
		cin >> N >> M;
		long long result = TIMEMAX * M;
		long long* imm_times;
		imm_times = new long long[N];

		for (int i = 0; i < N; i++) {
			cin >> imm_times[i];
		}
    
		long long start = 1, mid, sum;
		long long end = TIMEMAX*M;
		while (start <= end) {
			mid = (end + start) / 2;
			sum = 0;
			for (int i = 0; i < N; i++) {
				sum += (mid / imm_times[i]);
			}
			if (sum >= M) {
				result = min(result, mid);
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		cout << "#" << test_case << " " << result << endl;

	}
	return 0;
}
