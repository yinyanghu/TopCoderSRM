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

class Quacking {
public:
	int quack(string);
};


// quack
int Quacking::quack(string s) {
	int q, u, a, c, k;
	q = u = a = c = k = 0;

	int cur = 0;
	int ret = 0;

	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == 'q') {
			++ q;
			++ cur;
			ret = max(ret, cur);
		}
		else if (s[i] == 'u') {
			if (q == 0) return -1;
			-- q; ++ u;
		}
		else if (s[i] == 'a') {
			if (u == 0) return -1;
			-- u; ++ a;
		}
		else if (s[i] == 'c') {
			if (a == 0) return -1;
			-- a; ++ c;
		}
		else if (s[i] == 'k') {
			if (c == 0) return -1;
			-- cur; -- c;
		}
	}
	if (q + u + a + c + k != 0) return -1;
	return ret;
}

/*
int Quacking::quack(string s) {
	multiset<string> prefix;
	multiset<string>:: iterator it;

	int ret = 0;
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == 'q') {
			prefix.insert("q");
			int n = prefix.size();
			ret = max(ret, n);
		}
		else if (s[i] == 'u') {
			it = prefix.find("q");
			if (it == prefix.end()) return -1;
			prefix.erase(it);
			prefix.insert("qu");
		}
		else if (s[i] == 'a') {
			it = prefix.find("qu");
			if (it == prefix.end()) return -1;
			prefix.erase(it);
			prefix.insert("qua");
		}
		else if (s[i] == 'c') {
			it = prefix.find("qua");
			if (it == prefix.end()) return -1;
			prefix.erase(it);
			prefix.insert("quac");
		}
		else if (s[i] == 'k') {
			it = prefix.find("quac");
			if (it == prefix.end()) return -1;
			prefix.erase(it);
		}
	}
	if (!prefix.empty()) return -1;
	return ret;
}
*/


double test0() {
	string p0 = "quqacukqauackck";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string p0 = "kcauq";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string p0 = "quackquackquackquackquackquackquackquackquackquack";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string p0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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
	string p0 = "quqaquuacakcqckkuaquckqauckack";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
double test5() {
	string p0 = "quackqauckquack";
	Quacking * obj = new Quacking();
	clock_t start = clock();
	int my_answer = obj->quack(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
