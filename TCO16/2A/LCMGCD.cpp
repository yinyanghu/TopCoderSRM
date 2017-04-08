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

class LCMGCD {
public:
	string isPossible(vector <int>, int);
};

int F[2][35][35];

pair<int, int> getXY(int K) {
	int x, y;
	for (x = 0; K % 2 == 0; ++ x, K /= 2);
	for (y = 0; K % 3 == 0; ++ y, K /= 3);
	return make_pair(x, y);
}

bool solve(vector< pair<int, int> > A, pair<int, int> T) {
	memset(F, false, sizeof(F));
	F[0][A[0].first][A[0].second] = true;
	int n = A.size();
	for (int k = 1; k < n; ++ k) {
		int cur = k & 1;
		int prev = 1 - cur;
		int a = A[k].first;
		int b = A[k].second;
		memset(F[cur], false, sizeof(F[cur]));
		for (int i = 0; i < 35; ++ i)
			for (int j = 0; j < 35; ++ j)
				if (F[prev][i][j]) {
					F[cur][min(i, a)][min(j, b)] = true;
					F[cur][max(i, a)][max(j, b)] = true;
				}
	}
	return F[(n - 1) & 1][T.first][T.second];
}

string LCMGCD::isPossible(vector <int> x, int t) {
	pair<int, int> T = getXY(t);
	vector< pair<int, int> > A;
	for (int i = 0; i < x.size(); ++ i)
		A.push_back(getXY(x[i]));
	for (int t = 0; t < 2000; ++ t) {
		if (solve(A, T)) return "Possible";
		random_shuffle(A.begin(), A.end());
	}
	return "Impossible";
}


double test0() {
	int t0[] = {2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {4,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {6,12,24,18,36,72,54,108,216};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 36;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {6,27,81,729};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 72;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {100663296, 544195584, 229582512, 59049};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 60466176;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	int t0[] = {2,4,8,16,32,64};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 256;
	LCMGCD * obj = new LCMGCD();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	time = test7();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
