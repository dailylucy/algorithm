#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int T = 0;
int M = 0, N = 0, K = 0;

bool area[50][50] = { false };

void input() {
	int r, c;
	for (int i = 0; i < K; i++){
		cin >> c >> r;
		area[r][c] = true;
	}
}

void bfs(int n, int m) {
	queue<pair<int, int>> q;
	int r = 0, c = 0;
	q.push(make_pair(n, m));

    while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		area[r][c] = false;
		if (r > 0 && area[r - 1][c]){
			q.push(make_pair(r - 1, c));
            area[r-1][c] = false;            
        }
		if (r < N-1 && area[r + 1][c]){
			q.push(make_pair(r + 1, c));
            area[r+1][c] = false;            
        }
		if (c > 0 && area[r][c - 1]){
			q.push(make_pair(r, c - 1));
            area[r][c-1] = false;            
        }
		if (c < M - 1 && area[r][c + 1]){
			q.push(make_pair(r, c + 1));
            area[r][c+1] = false;            
        }
	}
}

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		memset(area, false, sizeof(area));
		int cnt = 0;

		input();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (area[r][c]) {
					cnt++;
					bfs(r, c);
				}
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
