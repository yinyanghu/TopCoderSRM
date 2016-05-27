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

class WolfHockeyTeamEasy {
public:
	int count(int, int);
};

const int MOD = 1000000007;

long long F[1010][1010][2];

long long add(const long long A, const long long B) {
	return (A + B) % MOD;
}

int WolfHockeyTeamEasy::count(int N, int K) {

	if (K >= 2 * N - 1) return 0;

	memset(F, 0, sizeof(F));
	F[1][0][0] = 1;

	for (int i = 0; i <= N; ++ i)
		for (int j = 0; j <= i; ++ j) {
			int num = 2 * N - 1 - i - j;
			if (num < 0) break;
			if (i < N) {
				F[i + 1][j][0] = add(F[i + 1][j][0], F[i][j][0]);
				F[i + 1][j][1] = add(F[i + 1][j][1], F[i][j][1]);
				if (num >= K)
					F[i + 1][j][1] = add(F[i + 1][j][1], F[i][j][0]);
			}
			if (j < i) {
				F[i][j + 1][(num >= K)] = add(F[i][j + 1][(num >= K)], F[i][j][0]);
				F[i][j + 1][1] = add(F[i][j + 1][1], F[i][j][1]);
			}
		}

	long long ans = F[N][N][1];
	ans = (ans * 2LL) % MOD;
	for (int i = 1; i <= N; ++ i)
		ans = (ans * (long long)i) % MOD;
	return (int)ans;
}

/*
long long F[2010][2010];
int N, K;

long long dp(int x, int delta) {
	if (delta < 0 || delta > x + 1) return 0;
	if (x == -1) return delta == 0;
	if (F[x][delta] != -1) return F[x][delta];
	return F[x][delta] = (dp(x - 1, delta - 1) + dp(x - 1, delta + 1)) % MOD;
}

int WolfHockeyTeamEasy::count(int n, int k) {
	N = n; K = k;
	memset(F, -1, sizeof(F));
	long long ans = 0;
	for (int i = K; i < 2 * N - 1; ++ i) {
		ans = (ans + dp(i, 2 * N - i - 1)) % MOD;
		cout << i << " " << ans << endl;
	}

	for (int i = 1; i <= N; ++ i)
		ans = (ans * (long long)i) % MOD;
	ans = (ans * 2LL) % MOD;
	return (int)ans;
}
*/


double test0() {
	int p0 = 2;
	int p1 = 0;
	WolfHockeyTeamEasy * obj = new WolfHockeyTeamEasy();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int p0 = 4;
	int p1 = 5;
	WolfHockeyTeamEasy * obj = new WolfHockeyTeamEasy();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1104;
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
	int p0 = 100;
	int p1 = 120;
	WolfHockeyTeamEasy * obj = new WolfHockeyTeamEasy();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 803057135;
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
	int p0 = 234;
	int p1 = 467;
	WolfHockeyTeamEasy * obj = new WolfHockeyTeamEasy();
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
double test4() {
	int p0 = 810;
	int p1 = 893;
	WolfHockeyTeamEasy * obj = new WolfHockeyTeamEasy();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 281618909;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
