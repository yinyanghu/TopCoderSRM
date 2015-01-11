#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define inf		2000

using namespace std;

class ArcadeManao {
public:
	int shortestLadder(vector <string>, int, int);
};

bool Map[51][51];

int part[51][51];

bool flag[51][51];

int partno;

int dist[1300][1300];

void dfs(int x, int y)
{
	flag[x][y] = false;
	part[x][y] = partno;
	if (flag[x][y + 1] && Map[x][y + 1]) dfs(x, y + 1);	
}

bool reach[1300];

int limit;

void walk(int x)
{
	reach[x] = true;
	for (int i = 0; i < partno; ++ i)
		if (!reach[i] && dist[x][i] <= limit)
			walk(i);
}

bool check(int source, int target)
{
	memset(reach, false, sizeof(reach));
	walk(source);
	return reach[target];
}

int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	int n = level.size();
	int m = level[0].length();

	memset(Map, false, sizeof(Map));
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			Map[i][j] = (level[i][j] == 'X');

	partno = 0;
	memset(flag, true, sizeof(flag));
	memset(part, -1, sizeof(part));
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			if (flag[i][j] && Map[i][j])
			{
				dfs(i, j);
				++ partno;
			}

	for (int i = 0; i < partno; ++ i)
	{
		dist[i][i] = 0;
		for (int j = i + 1 ; j < partno; ++ j)
			dist[i][j] = dist[j][i] = inf;
	}

	
	for (int i = 0; i < n - 1; ++ i)
		for (int j = 0; j < m; ++ j)
			if (Map[i][j])
			{
				for (int k = i + 1; k < n; ++ k)
					if (Map[k][j])
						dist[part[k][j]][part[i][j]] = dist[part[i][j]][part[k][j]] = min(dist[part[i][j]][part[k][j]], abs(i - k));
			}

	for (limit = 0; limit <= n; ++ limit)
		if (check(part[n - 1][0], part[coinRow - 1][coinColumn - 1]))
			break;
	return limit;
}


double test0() {
	string t0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 4;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
double test1() {
	string t0[] = {"XXXX",
 "...X",
 "XXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
	string t0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 3;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	string t0[] = {"X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
