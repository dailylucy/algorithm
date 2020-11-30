#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 1<== M, N, K <= 100 (자연수)
int M = 0, N = 0, K = 0;
bool map[100][100] = { false };

void input() {
	cin >> M >> N >> K;
	int lx = 0, ly = 0, rx = 0, ry = 0;

	for (int i = 0; i < K; i++) {
		cin >> lx >> ly >> rx >> ry;
		for (int r = M - ry; r <= M - 1 - ly; r++) {
			for (int c = lx; c <= rx - 1; c++) {
				map[r][c] = true;
			}
		}
	}
}

void output() {
	cout << "[=>] MAP" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int bfs(int startR, int startC) {
	queue<pair<int, int>> q;
	int cnt = 0;
	if (map[startR][startC]) return -1;

	q.push(make_pair(startR, startC));
	int row, col;
	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();

		if (map[row][col]) continue;
		map[row][col] = true;
		cnt++;

		// 상하좌우 FALSE인 부분 있으면 q에 넣기
		if (row > 0 && !map[row - 1][col])	  q.push(make_pair(row - 1, col)); // 상
		if (row < M - 1 && !map[row + 1][col])  q.push(make_pair(row + 1, col)); // 하
		if (col > 0 && !map[row][col - 1])	  q.push(make_pair(row, col - 1)); // 좌
		if (col < N - 1 && !map[row][col + 1])  q.push(make_pair(row, col + 1)); // 우
	}

	return cnt;
}

void dfs() {

}

int main() {
	input();
	//output();
	vector<int> result;
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			if (!map[r][c])
				result.push_back(bfs(r, c));
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}

