#include <iostream>

using namespace std;

int N;
int w[10][10];
bool isVisited[10];
double minw = 10e9;

void dfs(int depth, int start, int cur, double cur_sum){
    if (depth == N && start == cur){
        if (minw > cur_sum) minw = cur_sum;
    }
    for (int i = 0 ; i < N ; i++){
        if(isVisited[cur]) break;
        if(w[cur][i] <= 0) continue;
        isVisited[cur] = true;
        cur_sum += w[cur][i];
        if (minw >= cur_sum) dfs(depth+1, start, i, cur_sum );
        isVisited[cur] = false;
        cur_sum -= w[cur][i];     
    }
    return;
}

int main(){
    
    // input
    cin >> N;
    for (int i = 0 ; i< N ; i++){
        for (int j = 0 ; j< N ; j++){
            cin >> w[i][j];
        }
    }   
    
    dfs(0,0,0,0);
/*
    for (int i = 0 ; i< N; i++){
        dfs(0,i,i,0);
    }
*/
    cout << (int)minw << endl;
}
