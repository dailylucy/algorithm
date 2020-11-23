#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


vector <vector<int>> map(1001);
bool visited[1001] = { false };
int N = 0, M = 0;

void input() {
	int n1, n2;
	for (int i = 0; i < M; i++){
		cin >> n1 >> n2;
		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}
}

void dfs(int now) {
	if (visited[now]) return;
	visited[now] = true;
	for (int i = 1; i < N+1; i++) {
		if (find(map[now].begin(), map[now].end(), i) != map[now].end()) dfs(i);
	}
}

int main() {
	cin >> N >> M;
	int cnt=0;
	input();
	for (int i = 1; i < N + 1; i++)
	{
		if (visited[i]) continue;
		else {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
	return 0;
}
