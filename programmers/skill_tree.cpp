
// 스킬트리
// https://programmers.co.kr/learn/courses/30/lessons/49993#
 
// (A) 마지막에 해결한 부분 - 해결할 때 쓴 반례
//  skill = "XDC";  user_skill = ["CEZYX"];
 

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto user_skill : skill_trees) {
        int prevTreeIdx = -2;
        int nowTreeIdx = -2;
        for (int sIdx = 0; sIdx < skill.size(); sIdx++) {
             nowTreeIdx = user_skill.find(skill[sIdx]);   
             // 이전 스킬이 지금 스킬보다 뒤에 나옴.
             if ( nowTreeIdx > -1 && prevTreeIdx > nowTreeIdx ) break;
             // 이전 스킬이 없는데 지금 스킬이 있는 경우
             if( nowTreeIdx > -1 && prevTreeIdx == -1) break;
             if( sIdx == skill.size()-1 /* (A) 마지막에 해결한 부분 || prevTreeIdx == user_skill.size()-1*/){ 
                 answer++;
                 break;
             } 
             
             prevTreeIdx = nowTreeIdx;
        }
    }
    return answer;
}


