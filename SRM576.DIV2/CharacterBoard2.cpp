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

class CharacterBoard2 {
public:
	int countGenerators(vector <string>, int, int, int);
};

char generator[10010];

const int MOD = 1000000009;

int CharacterBoard2::countGenerators(vector <string> fragment, int W, int i0, int j0) {
			
	long long ret = 0;

	int n = fragment.size();
	int m = fragment[0].length();

	for (int len = 1; len <= W; ++ len)
	{
		for (int i = 0; i < len; ++ i)
			generator[i] = '.';
		
		bool check = true;
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				int pos = ((i + i0) * W + (j + j0)) % len;
				if (generator[pos] != '.' && generator[pos] != fragment[i][j])
				{
					check = false;
					break;
				}
				generator[pos] = fragment[i][j];	
			}
			if (!check) break;
		}
		if (!check) continue;
		long long k = 1;
		for (int i = 0; i < len; ++ i)
			if (generator[i] == '.')
				k = (k * 26) % MOD;
		ret = (ret + k) % MOD;
	}
	return (int)ret;
}


double test0() {
	string t0[] = {"dea",
 "abc"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 7;
	int p2 = 1;
	int p3 = 1;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"xyxxy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 6;
	int p2 = 1;
	int p3 = 0;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 28;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"gogogo",
 "jijiji",
 "rarara"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 6;
	int p2 = 0;
	int p3 = 0;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"abababacac",
 "aaacacacbb",
 "ccabababab"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 882;
	int p2 = 10;
	int p3 = 62;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 361706985;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 9031;
	int p2 = 9024;
	int p3 = 1959;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 173947456;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
