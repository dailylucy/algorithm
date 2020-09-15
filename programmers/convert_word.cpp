// 코딩테스트 고득점kit - BFS/DFS - 단어변환
// https://programmers.co.kr/learn/courses/30/lessons/43163


#include <string>
#include <vector>
using namespace std;

bool isVisited[51] = { false };
int mincnt = 51;
void DFS(vector<string> words, int now, int depth, string target)
{
    // v?
    if(isVisited[now]) return;
    isVisited[now] = true;
    
    // target 찾은 경우
    if(!words[now].compare(target))
    {
        if(mincnt > depth) {
            mincnt = depth;
            return;
        }
    }

    // 변환할 수 없는 경우
    if(depth >= words.size()-1) return; 
    
    // 다음 단어 확인
    int sz = words[0].length();
    int cnt;
    for(int i = words.size()-1 ; i >= 0 ; i--)
    {
        cnt = 0;
        for(int j = 0; j < sz ; j++)
        {
            if(words[now][j] != words[i][j]) 
            {
                if(cnt) {cnt = 0; break;}
                cnt++;
            }
        } 
        if(cnt) DFS(words, i, depth+1, target);
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    
    DFS(words, words.size()-1, 0, target);
    if(mincnt == 51) { answer = 0; }
    else { answer = mincnt; }     
    
    return answer;
}


/* 느낀점
 * 그래프로 만들 수 있는지 고민해보면 의외로 쉽게 DFS/BFS가 풀리는 것 같다.
 * 특히 DFS!!
 * 이번에도 예제 input을
 * begin : hit
 * target : cog
 * words : [hot, dot, dog, lot, log, cog]
   hit -- hot -- dot -- dog -- cog
           |      |      |     |
           ㄴ--- lot --- log --/  
 *
 * 이런 식으로 그래프로 보니깐 바로 DFS를 적용하기 편리했던 것 같다.
 * target number문제도 마찬가지!!
 */


