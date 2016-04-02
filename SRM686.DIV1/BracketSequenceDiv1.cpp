#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class BracketSequenceDiv1 {
public:
	long long count(string);
};

long long F[41][41];

long long dp(const string &s, int l, int r) {
	if (l > r) return 1;
	if (F[l][r] != -1) return F[l][r];
	long long ret = dp(s, l + 1, r);
	if (s[l] == '(') {
		for (int i = l + 1; i <= r; ++ i)
			if (s[i] == ')')
				ret += dp(s, l + 1, i - 1) * dp(s, i + 1, r);
	}
	if (s[l] == '[') {
		for (int i = l + 1; i <= r; ++ i)
			if (s[i] == ']')
				ret += dp(s, l + 1, i - 1) * dp(s, i + 1, r);
	}
	F[l][r] = ret;
	return ret;
}


long long BracketSequenceDiv1::count(string s) {
	memset(F, -1, sizeof(F));
	return dp(s, 0, s.size() - 1) - 1;
}

/*
long long F[41][41][41];
long long BracketSequenceDiv1::count(string s) {
	int n = s.size();
	memset(F, 0, sizeof(F));

	F[0][0][0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int a = 0; a <= i; ++ a)
			for (int b = 0; b <= i; ++ b) {
				if (a + b > i) continue;
				F[i][a][b] = F[i - 1][a][b];
				if (s[i - 1] == '(' && a >= 1) {
					F[i][a][b] += F[i - 1][a - 1][b];
				}
				else if (s[i - 1] == '[' && b >= 1) {
					F[i][a][b] += F[i - 1][a][b - 1];
				}
				else if (s[i - 1] == ')') {
					for (int j = 1; j < i; ++ j)
						if (s[j - 1] == '(' && a + 1 <= j) {
							F[i][a][b] += F[j][a + 1][b];
							break;
						}
				}
				else if (s[i - 1] == ']') {
					for (int j = 1; j < i; ++ j)
						if (s[j - 1] == '[' && b + 1 <= j) {
							F[i][a][b] += F[j][a][b + 1];
							break;
						}
				}
			}
	cout << F[2][0][0] << endl;
	cout << F[2][1][0] << endl;
	cout << F[4][0][0] << endl;
	return F[n][0][0] - 1;
}
*/


double test0() {
	string p0 = "()[]";
	BracketSequenceDiv1 * obj = new BracketSequenceDiv1();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 3LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "())";
	BracketSequenceDiv1 * obj = new BracketSequenceDiv1();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "()()";
	BracketSequenceDiv1 * obj = new BracketSequenceDiv1();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "([)]";
	BracketSequenceDiv1 * obj = new BracketSequenceDiv1();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "())[]][]([]()]]()]]]";
	BracketSequenceDiv1 * obj = new BracketSequenceDiv1();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 3854LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
