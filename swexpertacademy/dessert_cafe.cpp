#include<iostream>
#include<vector>
using namespace std;

int max_cnt = 0;

void input(int a[20][20], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void debug(int a[20][20], int n) {
	cout << "[=]debug" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int a[20][20], int n, int predir, int dirCnt, int sr, int sc, int cr, int cc, int cnt, bool dVisited[100]) {

	dVisited[a[cr][cc]] = true;
	if (cnt && cr == sr && cc == sc) {
		// 다시 돌아온 것.
		if (max_cnt < cnt) max_cnt = cnt;
		return;
	}

	cnt++;

	if (cr - 1 >= 0) {
		// 범위 내 && ( 바로전이 start가 아니면서 다음이 start || 방문한 적 없음 )
		if (cc - 1 >= 0 && ((cnt != 2 && cr-1==sr && cc-1==sc) || !dVisited[a[cr-1][cc-1]])) {
			// 사각형을 그려야 함 -> 방향이 3번 변경되어야 함. 
			// 처음 dirCnt가 0임을 고려 -> 방향 4번 초과하여 변경시 사각형 모양이 아님.
			if (predir != 1) { dirCnt++; }
			if (dirCnt <= 4) 
				dfs(a, n, 1, dirCnt, sr, sc, cr - 1, cc - 1, cnt, dVisited);
			if (predir != 1) dirCnt--;
		}
		if (cc + 1 <= n - 1 && ((cnt != 2 && cr - 1 == sr && cc + 1 == sc) || !dVisited[a[cr - 1][cc + 1]])) {
			if (predir != 2) { dirCnt++; }
			if (dirCnt <= 4)
				dfs(a, n, 2, dirCnt,sr, sc, cr - 1, cc + 1, cnt, dVisited);
			if (predir != 2) dirCnt--;
		}
	}
	if (cr + 1 <= n - 1) {
		if (cc - 1 >= 0 && ((cnt != 2 && cr + 1 == sr && cc - 1 == sc) || !dVisited[a[cr + 1][cc - 1]])) {
			if (predir != 3) { dirCnt++; }
			if (dirCnt <= 4)
				dfs(a, n, 3, dirCnt, sr, sc, cr + 1, cc - 1, cnt, dVisited);
			if (predir != 3) dirCnt--;
		}
		if (cc + 1 <= n - 1 && ((cnt != 2 && cr + 1 == sr && cc + 1 == sc) || !dVisited[a[cr + 1][cc + 1]])) {
			if (predir != 4) { dirCnt++; }
			if (dirCnt <= 4)
				dfs(a, n, 4, dirCnt,sr, sc, cr + 1, cc + 1, cnt, dVisited);
			if (predir != 4) dirCnt--;
		}
	}

	// 4방향을 모두 확인 후 dfs 모두 끝남,
	cnt--;
	dVisited[a[cr][cc]] = false;
	return;

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	int N = 0; 
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		max_cnt = 0;
		cin >> N;
		int area[20][20] = { 0 };

		input(area, N);
		//debug(area, N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bool dv[101] = { false };
				dfs(area, N, 0, 0, i, j, i, j, 0, dv);
			}
		}

		if (!max_cnt) max_cnt = -1;
		cout << "#" << test_case << " " << max_cnt << endl;


		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
