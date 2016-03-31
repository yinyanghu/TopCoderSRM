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

class EllysTree {
public:
	vector <int> getMoves(vector <int>);
};

const int maxN = 110;

bool graph[maxN][maxN];
int N;

int depth[maxN];

vector<int> child[maxN];

void DFS(int x, int d) {
	depth[x] = d;
	for (int i = 0; i < child[x].size(); ++ i)
		DFS(child[x][i], d + 1);
}

vector<int> path;

vector<int> empty;

bool visited[maxN];

bool check() {
	int m = path.size();

	bool v[maxN];
	for (int i = 0; i <= N; ++ i)
		v[i] = visited[i];

	int x = path[m - 1];
	for (int i = 0; i < N - m; ++ i) {
		int y = -1;
		for (int j = 1; j <= N; ++ j)
			if (!v[j] && graph[x][j] && (y == -1 || depth[j] > depth[y]))
				y = j;
		if (y == -1) return false;
		x = y;
		v[x] = true;
	}
	return true;
}

vector <int> EllysTree::getMoves(vector <int> parent) {
	memset(graph, false, sizeof(graph));
	N = parent.size();
	empty.clear();

	for (int i = 0; i <= N; ++ i)
		child[i].clear();

	for (int i = 0; i < N; ++ i) {
		int x = i + 1;
		int y = parent[i];
		child[y].push_back(x);

		while (y != 0) {
			graph[x][y] = graph[y][x] = true;
			y = parent[y - 1];
		}
	}

	DFS(0, 0);

	path.clear();
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; ++ i) {
		bool flag = false;
		for (int k = 1; k <= N; ++ k)
			if (!visited[k])
				if (i == 0 || graph[path[i - 1]][k]) {
					visited[k] = true;
					path.push_back(k);
					if (check()) {
						flag = true; break;
					}
					path.pop_back();
					visited[k] = false;
				}
		if (!flag) return empty;

	}

	return path;
}


double test0() {
	int t0[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysTree * obj = new EllysTree();
	clock_t start = clock();
	vector <int> my_answer = obj->getMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {3, 4, 5, 0, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysTree * obj = new EllysTree();
	clock_t start = clock();
	vector <int> my_answer = obj->getMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {1, 2, 3, 4, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysTree * obj = new EllysTree();
	clock_t start = clock();
	vector <int> my_answer = obj->getMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0, 6, 6, 2, 6, 1, 3, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysTree * obj = new EllysTree();
	clock_t start = clock();
	vector <int> my_answer = obj->getMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2, 4, 1, 3, 7, 6, 5, 8 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
