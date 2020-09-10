// 촌수 계산
// https://www.acmicpc.net/problem/2644
// C++ 14
// 1984KB - 0ms


#include <iostream>
#include <vector>

using namespace std;

int N, M, end1, end2;
int mincnt = 101;


vector<vector<int>> graph(101);
bool isVisited[101] = { false };

void addEdges() 
{
	int tmp1, tmp2;
	for (auto i = 0; i < M; i++) 
	{
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
}

void dfs(int node, int sum) 
{
	if (isVisited[node]) {  return; }
	sum++;
	isVisited[node] = true;
	if (node == end2) { if (mincnt > sum) mincnt = sum; sum--; return; }

	for (auto i = 0; i < graph[node].size(); i++) {
		dfs(graph[node][i], sum);
	}
	sum--;
}

/* 위와 조금 다르지만 정답나온 dfs 함수 코드.
 * 현재 노드가 아닌 자식 노드를 확인한 후 자식노드로 갈 때, sum을 증가시킴.
 * 이 경우 main에서 mincnt를 그대로 출력한다. 즉, 이 함수를 위의 dfs 대신 사용시
 * [68 line - main에서 출력부분] else cout << mincnt << endl; 로 변경할 것
 
void dfs(int node, int sum) 
{
	if (isVisited[node]) {  return; }
	
	isVisited[node] = true;
	if (node == end2) { if (mincnt > sum) mincnt = sum; sum--; return; }

	for (auto i = 0; i < graph[node].size(); i++) {
		sum++;
		dfs(graph[node][i], sum);
		sum--;
	}
}
*/

int main() {
	cin >> N >> end1 >> end2 >> M;
	addEdges();
	dfs(end1, 0);
	if (mincnt == 101) cout << -1 << endl;
	else	             cout << mincnt-1 << endl;
	return 0;
}


/* 느낀점 
 생각을 심플하게 할 것.
 문제를 보고 마구잡이로 풀지 않고, 
 알고리즘 개념을 문제에 어떻게 적용할 수 있는지와
 이 문제에서 특별히 고려해야하는 점을 생각해보기!
*/


