// 수정중(정답은 나오는 코드임)

// 알고리즘 문제 url
// https://www.acmicpc.net/problem/9095

#include <algorithm>  
#include <string>  
#include <iostream>  
#include <vector>
#include <cstring>
using namespace std;

vector<string> cases;

int input[12] = { '0','1','2','3','4','5','6','7','8','9','10','11' };

void out_cases(vector<string> c) {
    for (int i = 0; i < c.size(); i++) {
        cout << cases[i] << endl;
    }
}
void out_str(string s) {
    cout << "[+]DEBUG";
    cout << s << endl;
}

void solution(int x) {
    cases.clear();
    int tmp = x;
    for (int j = (tmp / 3); j > 0; j--) {
        tmp = x;
        string tmp_str = "";
        //cout << "seonae" << endl;
        tmp_str.push_back(input[j]);
        //cout << "!!!!!!!!!!!" << tmp_str << endl;
        tmp -= 3 * j;
        int tmp2 = tmp;
        for (int m = tmp2 / 2; m >= 0; m--) {
            tmp2 = tmp;
            tmp_str.push_back(input[m]);
            if (m) tmp2 -= 2 * m;
            tmp_str.push_back(input[tmp2]);
            //out_str(tmp_str);
            cases.push_back(tmp_str);
            tmp_str.pop_back();
            tmp_str.pop_back();
        }
    }

    tmp = x;
    for (int m = tmp / 2; m > 0; m--) {
        tmp = x;
        string tmp_str = "0";
        tmp_str.push_back(input[m]);
        tmp -= 2 * m;
        tmp_str.push_back(input[tmp]);
        //out_str(tmp_str);
        cases.push_back(tmp_str);
        tmp_str.pop_back();
        tmp_str.pop_back();
    }

    //cout << "test" << endl;
    string tmp_str = "00";
    tmp_str.push_back(input[x]);
    cases.push_back(tmp_str);
    //out_str(tmp_str);
}

int perm(vector<string> s) {
    int perm_sum = 0;
    char tmp[11];
    for (int i = 0; i < s.size(); i++) {

        memset(tmp, 0, sizeof(char) * 11);
        //cout << "!test!" << s[i] << endl;
        char tmpchr = s[i][2];
        int size1 = atoi(&tmpchr);
        tmpchr = s[i][1];
        int size2 = atoi(&tmpchr);
        tmpchr = s[i][0];
        int size3 = atoi(&tmpchr);
        //cout << "size3" << size3 <<  endl;
        //cout << "size2" << size2 << endl;
        //cout << "size1" << size1 << endl;

        memset(tmp, input[3], size3);
        memset(tmp + size3, input[2], size2);
        memset(tmp + size3 + size2, input[1], size1);


        //cout << tmp << endl;
        string stmp(tmp);
        sort(stmp.begin(), stmp.end());
        do {
            perm_sum++;
            //cout << "[+]PERM :: "<< stmp << endl;
        } while (next_permutation(stmp.begin(), stmp.end()));
        //return perm_sum;
    }
    return perm_sum;
}

int main()
{
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        // 각 케이스마다
        cin >> N;
        solution(N);
        //out_cases(cases);
        //cout << "perm(cases) :: " << perm(cases) << endl;
        cout << perm(cases) << endl;

    }
    return 0;
}
