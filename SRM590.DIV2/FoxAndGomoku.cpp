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

class FoxAndGomoku {
public:
	string win(vector <string>);
};

string FoxAndGomoku::win(vector <string> board) {

    int N = board[0].size();

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
        {
            if (board[i][j] == '.') continue;
            bool flag;
            if (i + 4 < N)
            {
                flag = true;
                if (board[i + 1][j] == '.') flag = false;
                if (board[i + 2][j] == '.') flag = false;
                if (board[i + 3][j] == '.') flag = false;
                if (board[i + 4][j] == '.') flag = false;
                if (flag) return "found";
            }
            if (j + 4 < N)
            {
                flag = true;
                if (board[i][j + 1] == '.') flag = false;
                if (board[i][j + 2] == '.') flag = false;
                if (board[i][j + 3] == '.') flag = false;
                if (board[i][j + 4] == '.') flag = false;
                if (flag) return "found";
            }
            if (i + 4 < N && j + 4 < N)
            {
                flag = true;
                if (board[i + 1][j + 1] == '.') flag = false;
                if (board[i + 2][j + 2] == '.') flag = false;
                if (board[i + 3][j + 3] == '.') flag = false;
                if (board[i + 4][j + 4] == '.') flag = false;
                if (flag) return "found";
            }
            if (i + 4 < N && j - 4 >= 0)
            {
                flag = true;
                if (board[i + 1][j - 1] == '.') flag = false;
                if (board[i + 2][j - 2] == '.') flag = false;
                if (board[i + 3][j - 3] == '.') flag = false;
                if (board[i + 4][j - 4] == '.') flag = false;
                if (flag) return "found";
            }
        }
    return "not found";
}


double test0() {
	string t0[] = {"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "not found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "not found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	string t0[] = {"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test8() {
	string t0[] = {".....",
 ".....",
 ".....",
 ".....",
 "....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoxAndGomoku * obj = new FoxAndGomoku();
	clock_t start = clock();
	string my_answer = obj->win(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "not found";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test7();
	if (time < 0)
		errors = true;
	
	time = test8();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
