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

class CyclesNumber {
public:
	vector <int> getExpectation(vector <int>, vector <int>);
};

const int maxN = 100010;
const int maxM = 305;
const long long MOD = 1000000007LL;

long long S1[maxN][maxM];
long long S2[maxM][maxM];
long long factorial[maxM];

vector <int> CyclesNumber::getExpectation(vector <int> n, vector <int> m) {
	factorial[0] = 1;
	for (int i = 1; i < maxM; ++ i)
		factorial[i] = (factorial[i - 1] * (long long)i) % MOD;

	memset(S1, 0, sizeof(S1));
	S1[0][0] = 1;
	for (int i = 1; i < maxN; ++ i) {
		for (int j = 1; j < maxM; ++ j)
			S1[i][j] = (S1[i - 1][j - 1] + ((long long)(i - 1) * S1[i - 1][j]) % MOD) % MOD;
	}

	memset(S2, 0, sizeof(S2));
	S2[0][0] = 1;
	for (int i = 1; i < maxM; ++ i) {
		for (int j = 1; j < i; ++ j)
			S2[i][j] = (S2[i - 1][j - 1] + ((long long)j * S2[i - 1][j]) % MOD) % MOD;
		S2[i][i] = 1;
	}

	vector<int> ret;
	for (int i = 0; i < n.size(); ++ i) {
		int N = n[i];
		int M = m[i];

		long long ans = 0;
		for (int k = 0; k <= M; ++ k)
			ans = (ans + (((S1[N + 1][k + 1] * S2[M][k]) % MOD) * factorial[k]) % MOD) % MOD;

		ret.push_back((int)ans);
	}

	return ret;
}


double test0() {
	int t0[] = {2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CyclesNumber * obj = new CyclesNumber();
	clock_t start = clock();
	vector <int> my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CyclesNumber * obj = new CyclesNumber();
	clock_t start = clock();
	vector <int> my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {6 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 3, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CyclesNumber * obj = new CyclesNumber();
	clock_t start = clock();
	vector <int> my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 9, 53 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {10, 20, 30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 20, 30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CyclesNumber * obj = new CyclesNumber();
	clock_t start = clock();
	vector <int> my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {586836447, 544389755, 327675273 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
