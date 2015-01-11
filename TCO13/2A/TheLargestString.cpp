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

class TheLargestString {
public:
	string find(string, string);
};

string TheLargestString::find(string s, string t) {
	int N = s.length();
	vector< pair<string, string> > F(N + 1, make_pair("", ""));

	for (int i = 0; i < N; ++ i)
	{
		for (int j = i; j >= 0; -- j)
		{
			string x = F[j].first + s[i];
			string y = F[j].second + t[i];
			F[j + 1] = max(F[j + 1], make_pair(x, y));
		}
	}

	string ret = "";
	for (int i = 0; i <= N; ++ i)
		ret = max(ret, F[i].first + F[i].second);

	return ret;
}

/*

Competition Code:

string TheLargestString::find(string s, string t) {
	int n = s.size();
	string A, B;
	A = B = "";
	string tempA, tempB;
	string ansA, ansB;
	tempA = tempB = ansA = ansB = "";
	int x = 0;
	int i;
	while (x < n)
	{
		string nextA = ansA;
		string nextB = ansB;
		for (i = x; i < n; ++ i)
		{
			tempA = ansA + s[i];
			tempB = ansB + t[i];
			if (tempA + tempB > nextA + nextB)
			{
				nextA = tempA;
				nextB = tempB;
				x = i;
			}
		}
		ansA = nextA;
		ansB = nextB;
		x = x + 1;
	}
	return ansA + ansB;
	int n = s.size();
	char up = '0';
	char down = '0';
	string A = "";
	string B = "";
	int k = 0;
	for (int i = 0; i < n; ++ i)
		if (s[i] > up)
		{
			up = s[i];
			down = t[i];
			k = i;
		}
		else if (s[i] == up && t[i] >= up && t[i] > down)
		{
			down = t[i];
			k = i;
		}
	A = A + s[k];
	B = B + t[k];
	for (int x = k + 1; x < n;)
	{
		up = '0';
		k = -1;
		for (int i = x + 1; i < n; ++ i)
		{
			if (s[i] > up && s[i] >= down)	
			{
				up = s[i];
				k = i;
			}
		}
		if (k == -1) break;
		A = A + s[k];
		B = B + t[k];
		x = k;
	}
	return A + B;
}

*/


double test0() {
	string p0 = "ab";
	string p1 = "zy";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "by";
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
	string p0 = "abacaba";
	string p1 = "zzzaaaa";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "cbaaaa";
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
	string p0 = "x";
	string p1 = "x";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "xx";
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
	string p0 = "abbabbabbababaaaabbababab";
	string p1 = "bababbaabbbababbbbababaab";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bbbbbbbbbbbbbbbbbbaaab";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
