#include <vector>
#include <iostream>
#include <queue>
//#include <Windows.h>
using namespace std;


bool map[50][50] = { false };
int C = 0, R = 0;
// 시계방향으로 상, 상우, 우, 하우, 하, 하좌, 좌, 상좌 
int dirR[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dirC[8] = { 0,  1, 1, 1, 0, -1, -1, -1};

void input() {
	int tmp = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> tmp;
			map[r][c] = tmp;
		}
	}
}

void bfs(int row, int col) {
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
    map[row][col] = false;
	int r = 0, c = 0;
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			if ( r + dirR[i] >= 0 &&
				   r + dirR[i] < R  &&
				   c + dirC[i] >= 0 &&
				   c + dirC[i] < C  &&
				   map[r + dirR[i]][c + dirC[i]]) {
                 map[r + dirR[i]][c + dirC[i]] = false;
				         q.push(make_pair(r + dirR[i], c + dirC[i]));
			}
		}
	}
}


int main() {
	int cnt = 0;
	while (true) {
		cnt = 0;
		cin >> C >> R;
		if (!C && !R) return 0;
		input();

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (map[r][c]) {
					cnt++;
					bfs(r, c);
				}
			}
		}
		cout << cnt << endl;
	}
}
