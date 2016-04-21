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

class ReplacingDigit {
public:
	int getMaximumStockWorth(vector <int>, vector <int>);
};

int digit[7][10];

int ReplacingDigit::getMaximumStockWorth(vector <int> A, vector <int> D) {
	memset(digit, 0, sizeof(digit));
	int ret = 0;

	for (int i = 0; i < A.size(); ++ i) {
		int x = A[i];
		ret += x;
		for (int n = 0; x; x /= 10) {
			++ digit[n][x % 10]; ++ n;
		}
	}

	int ptr = 8;
	while (ptr >= 0 && D[ptr] == 0) -- ptr;
	if (ptr == -1) return ret;

	int base = 1000000;
	for (int n = 6; n >= 0; -- n) {
		for (int d = 0; d <= 9; ++ d) {
			if (d >= ptr + 1) break;
			while (digit[n][d]) {
				ret += base * (ptr + 1 - d);
				-- digit[n][d];

				-- D[ptr];
				while (ptr >= 0 && D[ptr] == 0) -- ptr;
				if (ptr == -1) return ret;
				if (d >= ptr + 1) break;
			}
		}
		base /= 10;
	}
	return ret;
}


double test0() {
	int t0[] = {100, 90};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 745;
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
	int t0[] = {9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	int t0[] = {123456};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 988777;
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
	int t0[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {11, 2, 8, 10, 7, 6, 3, 1, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3297500;
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
	int t0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {111, 111, 111, 111, 111, 111, 111, 111, 111};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 198;
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
double test5() {
	int t0[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ReplacingDigit * obj = new ReplacingDigit();
	clock_t start = clock();
	int my_answer = obj->getMaximumStockWorth(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 170900000;
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
	
	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
