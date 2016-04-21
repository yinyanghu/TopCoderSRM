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

class ParenthesesDiv2Hard {
public:
	int minSwaps(string, vector <int>, vector <int>);
};


int f(string s) {
	while (1) {
		size_t p = s.find("()");
		if (p == string::npos) break;
		s.erase(p, 2);
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == '(') ++ a;
		if (s[i] == ')') ++ b;
	}
	int K = min(a, b);
	return (K >> 1) + (K & 1);
}

int ParenthesesDiv2Hard::minSwaps(string s, vector <int> L, vector <int> R) {

	int need = 0;
	for (int i = 0; i < L.size(); ++ i) {
		if ((R[i] - L[i]) % 2 == 0) return -1;
		need += (R[i] - L[i] + 1) >> 1;
	}
	int totalL = 0;
	for (int i = 0; i < s.size(); ++ i)
		if (s[i] == '(') ++ totalL;
	if (totalL < need || s.size() - totalL < need) return -1;


	int pos = 0;
	int neg = 0;

	int ret = 0;

	for (int i = 0; i < L.size(); ++ i) {
		int l = L[i];
		int r = R[i];
		int count = 0;
		for (int j = l; j <= r; ++ j) {
			if (s[j] == '(') ++ count; else -- count;
		}
		if (count > 0)
			pos += count / 2;
		else if (count < 0)
			neg += -count / 2;
		ret += f(s.substr(l, r - l + 1));
	}
	ret += max(pos, neg);
	return ret;
}


double test0() {
	string p0 = ")(";
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string p0 = "(())";
	int t1[] = {0,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string p0 = "(((())";
	int t1[] = {0,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	string p0 = "(((((((((";
	int t1[] = {0,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
double test4() {
	string p0 = "))()())((()()()()()())))((((((";
	int t1[] = {1,6,13,17,23,25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,7,16,20,24,28};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
double test5() {
	string p0 = "(";
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ParenthesesDiv2Hard * obj = new ParenthesesDiv2Hard();
	clock_t start = clock();
	int my_answer = obj->minSwaps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
