// 안전 영역
// https://www.acmicpc.net/problem/2468
// C++ 14
// 2060KB	- 20ms

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

// 2 <= N <= 100 : 지역 크기
int N = 2;
int areaMaxCnt = 0;
int minht = 100, maxht = 1;

int area[100][100] = { 0 };
int isVisited[100][100] = { false };

void inputData()
{
	int nowdata = 0; 
	for (auto i = 0; i < N; i++)
	{
		for (auto j = 0; j < N; j++)
		{
			cin >> nowdata;
			area[i][j] = nowdata;
			if (nowdata < minht) { minht = nowdata; }
			if (nowdata > maxht) { maxht = nowdata; }
		}
	}
}

int dfs(int rain)
{
	int cnt = 0;
	for (auto i = 0; i < N; i++)
	{
		for (auto j = 0; j < N; j++)
		{
			// 이미 방문했으면 안감.
			if (isVisited[i][j]) continue;
			if (rain < area[i][j]) {
				stack<int> s;
				s.push(i*N+j);
				isVisited[i][j] = true;
				while (!s.empty())
				{
					int now = s.top();
					s.pop();
					int r = now/N;
					int c = now%N;
					
          				// 주변 노드 전부 스택에 넣기
					if(r)
					{
            					// 비 높이 < 영역 높이일 때만 갈수있다고 가정
            					// 즉, 비 높이 = 영역높이이면 잠겼다고 본다.
            					// 따라서 비 높이가 영역 최대 높이(예제에서 9)일 때부터 안전영역의 개수는 0이다. 
						if (!isVisited[r - 1][c] && rain < area[r - 1][c]) { isVisited[r-1][c]=true; s.push((r - 1) * N + c); }
					}
					if(r<N-1)
					{
						if (!isVisited[r + 1][c] && rain < area[r + 1][c]) { isVisited[r+1][c] = true; s.push((r + 1) * N + c); }
					}
					if(c)
					{
						if (!isVisited[r][c - 1] && rain < area[r][c - 1]) { isVisited[r][c - 1] = true; s.push(r * N + (c - 1)); }
					}
					if(c<N-1)
					{
						if (!isVisited[r][c + 1] && rain < area[r][c + 1]) { isVisited[r][c + 1] = true; s.push(r * N + (c + 1)); }
					}
				}
				cnt++;
			} 
		}
	}
	return cnt;
}

int main() {
	
	int tmpCnt = 1;
	cin >> N;
	inputData();
	
	// 비 높이에 따라 dfs를 돌려야 함.
  	// 비가 안올 경우인 비높이 = 0부터
  	// 안전영역의 개수가 0이 되는 (비높이 = 영역 최대 높이)까지 혹은 (비높이 = 영역 최대 높이-1)까지
  	// 어차피 영역 최대 높이에서는 0이 나옴. 가장 낮은 값이 나오므로 문제 푸는데 영향 X.
	for (auto i = 0; /*tmpCnt!=0 &&*/ i < maxht ; i++)
	{
		memset(isVisited, 0, sizeof(isVisited));
		tmpCnt = dfs(i);
		if (areaMaxCnt < tmpCnt) areaMaxCnt = tmpCnt;
	}
	cout << areaMaxCnt << endl;
	return 0;
}




/* 
 * 느낀점
 * 
 * 문제에 맞게 알고리즘을 잘 적용하는게 중요한 것 같다. 
 * 
 * 비가 안오는 경우도 고려해야 하는데, 
 * 그 경우를 고려하지 않아서 75%에서 틀렸다고 떠서 다시 문제를 읽고 알았다.
 *
 */


