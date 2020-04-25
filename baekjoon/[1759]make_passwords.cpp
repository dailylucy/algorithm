// 알고리즘 문제 url
// https://www.acmicpc.net/problem/1759
#include <iostream>  
#include <vector>
#include <algorithm>

using namespace std;
char vowels[5] = { 'a','e','i','o','u' };

//vector<char> input;
char input[15];
vector<char> input_v;
vector<char> input_c;
bool isVisited[15] = { false };
bool isVisited_v[15] = { false };
string password = "";
string password_v = "";

vector<string> passwds_v;
vector<string> passwds_c;
vector<string> passwds;
int L, C;

void out_vector(vector<char> chrs) {
	for (int i = 0; i < chrs.size(); i++) {
		cout << chrs[i] << " ";
	}
	cout << endl;
}
void out_vector(vector<string> strings) {
	for (int i = 0; i < strings.size(); i++) {
		cout << strings[i] << endl;
	}
	//cout << endl;
}
void solution(int cur, int depth, int total_dep, int consonants, bool vowel) {
	if (depth == total_dep && consonants) {
		sort(password.begin(), password.end());
		//cout << password << endl;
		passwds_c.push_back(password);
		return;
	}
	for (int i = cur; i < input_c.size(); i++) {
		if (isVisited[i]) continue;
		isVisited[i] = true;
		password.push_back(input_c[i]);
		consonants += 1;
		solution(i+1, depth + 1, total_dep, consonants, vowel);
		isVisited[i] = false;
		password.pop_back();
		consonants -= 1;
	}

}

void solution_v(int cur, int depth, int total_dep, int consonants, int vowel) {
	if (depth == total_dep && vowel) {
		sort(password_v.begin(), password_v.end());
		//cout << password_v << endl;
		passwds_v.push_back(password_v);
		return;
	}
	for (int i = cur; i < input_v.size(); i++) {
		if (isVisited_v[i]) continue;
		isVisited_v[i] = true;
		password_v.push_back(input_v[i]);
		//cout << "[+]DEBUG :: " << input_v[i] << endl;
		vowel += 1;
		solution_v(i + 1, depth + 1, total_dep, consonants, vowel);
		isVisited_v[i] = false;
		password_v.pop_back();
		vowel -= 1;
	}

}

int main()
{
	// L = length of password
	// number of input charaters 
	// 3 <= L <= C <= 15

	cin >> L;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> input[i];
		if (find(vowels, vowels + 5, input[i]) != vowels + 5)
			input_v.push_back(input[i]);
		else
			input_c.push_back(input[i]);
	}

	sort(input_v.begin(), input_v.end());
	sort(input_c.begin(), input_c.end());

	/* input test
	cout << "input_v :: ";
	out_vector(input_v);
	cout << "input_c :: ";
	out_vector(input_c);
	*/

	/*
	cout << "=> solution[L-1] :: " << endl;
	solution(0, 0, L - 1, 0, false);

	cout << "=> solution[L-2] :: " << endl;
	solution(0, 0, L - 2, 0, false);
	*/

	
	//cout << "SOLUTION[DEP]" << endl;
	
	// 자음 2개부터 L-1(모음하나 포함가능)까지
	for (int i = 2; i < L; i++) {
		//cout << "=> solution[" << i << "] ::" << endl;
		solution(0, 0, i, 0, false);
	}
	

	//solution_v(0, 0, 2, 0, 0);

	for (int i = 1; i < L-1; i++) {
		//cout << "=> solution[" << i << "] ::" << endl;
		solution_v(0, 0, i, 0, 0);
	}

	//cout << "[=] CONSONANTS RESULT" << endl;
	//out_vector(passwds_c);
	//cout << "[=] VOWELS RESULT" << endl;
	//out_vector(passwds_v);

	//cout << "++++++++++++++++++++ [RESULT] ++++++++++++++++++++" << endl;
	for (int i = 0; i < passwds_v.size(); i++) {
		for (int j = 0; j < passwds_c.size(); j++) {
			if (passwds_v[i].length() + passwds_c[j].length() == L){
				string tmp_r = passwds_v[i] + passwds_c[j];
				sort(tmp_r.begin(), tmp_r.end());
				passwds.push_back(tmp_r);
			}
		}
	}
	sort(passwds.begin(), passwds.end());
	out_vector(passwds);
}
