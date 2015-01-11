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

const long long MOD = 1000000007LL;

class FoxAndShogi {
public:
	int differentOutcomes(vector <string>);
};

const int limitsize = 50;

long long dp(int N, const string &X)
{
    vector< pair<int, int> > line;
    int f[limitsize][limitsize];

    memset(f, 0, sizeof(f));
    line.clear();

    for (int i = 0; i < N; ++ i)
        if (X[i] == 'U')
            line.push_back(make_pair(i, -1));
        else if (X[i] == 'D')
            line.push_back(make_pair(i, 1));

    if (line.size() == 0) return 1;

    for (int i = line[0].first; i >= 0 && i < N; i += line[0].second)
        f[0][i] = 1;

    for (int i = 1; i < line.size(); ++ i)
        for (int j = line[i].first; j >= 0 && j < N; j += line[i].second)
            for (int k = 0; k < j; ++ k)
                f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;

    long long ret = 0;
    for (int i = 0; i < N; ++ i)
        ret = (ret + f[line.size() - 1][i]) % MOD;

    return ret;
}

int FoxAndShogi::differentOutcomes(vector <string> board) {
    int N = board[0].size();

    long long ans = 1;

    string line;

    for (int i = 0; i < N; ++ i)
    {
        line = "";
        for (int j = 0; j < N; ++ j)
            line += board[j][i];
        ans = (ans * dp(N, line)) % MOD;
    }
    return (int)ans;
}


double test0() {
	string t0[] = {".D.",
 "...",
 "..."}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
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
double test1() {
	string t0[] = {".D.",
 "...",
 ".U."}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
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
double test2() {
	string t0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3125;
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
	string t0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 900;
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
	string t0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2268;
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
	string t0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 999999937;
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
double test6() {
	string t0[] = {"..",
 ".."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndShogi * obj = new FoxAndShogi();
	clock_t start = clock();
	int my_answer = obj->differentOutcomes(p0);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
