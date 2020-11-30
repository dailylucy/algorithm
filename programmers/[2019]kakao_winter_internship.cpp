
// 크레인 인형뽑기 게임
// https://programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector> 

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int now = 0;
    vector<int> bucket;
    int prev = -1;
    for(int i = 0 ; i < moves.size(); i++){
        now = moves[i]-1;
        for(int r = 0 ; r < board.size(); r++){
            if(board[r][now]) {
                // 첫 move?
                // 이전 노드와 현재 비교
                if(prev != -1 && prev == board[r][now]) {
                    // 같으면 제거
                    bucket.pop_back();
                    answer = answer + 2;
                }
                else{
                    // bucket에 담기
                    bucket.push_back(board[r][now]);            
                }
                // board 변경
                board[r][now] = 0;
                prev = bucket[bucket.size()-1];        
                break;
            }
        }
    }
    return answer;
}

