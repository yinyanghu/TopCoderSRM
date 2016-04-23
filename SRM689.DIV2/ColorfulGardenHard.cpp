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

class ColorfulGardenHard {
public:
	int count(string, string);
};

int F[16][1 << 16][16];

const int MOD = 1000000007;

int C[26];

int f(int x, int d) {
	if (x % d == 0) return x / d;
	long long temp = (long long)x;
	while (temp % d != 0)
		temp = temp + (long long)MOD;
	temp = temp / d;
	temp = temp % MOD;
	return (int)temp;
}

int ColorfulGardenHard::count(string garden, string forbid) {
	int n = garden.size();
	int m = 1 << n;
	memset(F, 0, sizeof(F));
	for (int i = 0; i < n; ++ i)
		if (garden[i] == forbid[0])
			F[0][1 << i][i] = 0;
		else
			F[0][1 << i][i] = 1;
	for (int i = 1; i < n; ++ i) {
		for (int k = 0; k < m; ++ k)
			for (int cur = 0; cur < n; ++ cur) {
				if (garden[cur] == forbid[i]) continue;
				if ((1 << cur) & k) {
					int kk = k - (1 << cur);
					for (int last = 0; last < n; ++ last)
						if (garden[last] != garden[cur] && (kk & (1 << last)))
							F[i][k][cur] = (F[i][k][cur] + F[i - 1][kk][last]) % MOD;
				}

			}
	}
	int ret = 0;
	for (int i = 0; i < n; ++ i)
		ret = (ret + F[n - 1][m - 1][i]) % MOD;

	memset(C, 0, sizeof(C));
	for (int i = 0; i < garden.size(); ++ i)
		++ C[garden[i] - 'a'];

	for (int i = 0; i < 26; ++ i)
		for (int k = 2; k <= C[i]; ++ k)
			ret = f(ret, k);
	return ret;
}


double testA() {
	string p0 = "adadcdbcceadccd";
	string p1 = "ebcabbaeabeecab";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 41593;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test0() {
	string p0 = "aaabbb";
	string p1 = "cccccc";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "aabbcc";
	string p1 = "aabbcc";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "aaaabb";
	string p1 = "xxxxxx";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "abcdefghijklmno";
	string p1 = "zzzzzzzzzzzzzzz";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 674358851;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "a";
	string p1 = "b";
	ColorfulGardenHard * obj = new ColorfulGardenHard();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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

	time = testA();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
