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

class DevuAndPlantingTrees {
public:
	int maximumTreesDevuCanGrow(vector <string>);
};

int DevuAndPlantingTrees::maximumTreesDevuCanGrow(vector <string> garden) {
	int ret = 0;
	int N = garden[0].size();
	for (int i = 0; i < N; ++ i) {
		if (garden[0][i] == '*' || garden[1][i] == '*')	{
			++ ret;
			++ i;
			continue;
		}
		if (i + 1 < N && (garden[0][i + 1] == '*' || garden[1][i + 1] == '*')) continue;
		++ ret;
		++ i;
	}
	return ret;
}


double test0() {
	string t0[] = {"..", ".."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
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
double test1() {
	string t0[] = {"..", ".*"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
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
double test2() {
	string t0[] = {"...",
"..*"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
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
double test3() {
	string t0[] = {".....*..........",
".*.......*.*..*."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {"....*.*.*...........*........",
"*..........*..*.*.*....*...*."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	string t0[] = {".....*..*..........*............................*",
"*..*.............*...*.*.*.*..*.....*.*...*...*.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DevuAndPlantingTrees * obj = new DevuAndPlantingTrees();
	clock_t start = clock();
	int my_answer = obj->maximumTreesDevuCanGrow(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 23;
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
