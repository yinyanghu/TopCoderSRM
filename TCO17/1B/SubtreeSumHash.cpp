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

using namespace std;

const int MOD = 1e9 + 7;

class SubtreeSumHash {
public:
	int count(vector <int>, vector <int>, int);

private:
	int base;
	int ans;

	vector< vector<int> > children;
	int dfs(int, vector<int> &);
};

int power_mod(int a, int b) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1)
			ret = (long long)ret * a % MOD;
		a = (long long)a * a % MOD;
	}
	return ret;
}

int SubtreeSumHash::dfs(int x, vector<int> &weight) {
	int ret = power_mod(base, weight[x]);
	for (int child : children[x]) {
		int k = dfs(child, weight) + 1;
		ret = (long long)ret * k % MOD;
	}
	ans = (ans + ret) % MOD;
	return ret;
}

int SubtreeSumHash::count(vector <int> weight, vector <int> p, int x) {
	for (int i = 0; i < weight.size(); ++ i)
		children.push_back(vector<int>());
	for (int i = 0; i < p.size(); ++ i) {
		children[p[i]].push_back(i + 1);
	}
	base = x;

	ans = 0;
	dfs(0, weight);
	return ans;
}


double test0() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 10;
	SubtreeSumHash * obj = new SubtreeSumHash();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1102110;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {123456789,987654321,111111111,999999999};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	SubtreeSumHash * obj = new SubtreeSumHash();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 11;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	vector <int> p1;
	int p2 = 10;
	SubtreeSumHash * obj = new SubtreeSumHash();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 999999937;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {3,7,6,8,9,4,2,1,5,6,7,8,9,6,1,2,3,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,0,3,1,1,2,0,0,3,7,8,9,0,0,4,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 987654321;
	SubtreeSumHash * obj = new SubtreeSumHash();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 46327623;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
