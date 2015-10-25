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

class FoxMeeting {
public:
	int maxDistance(vector <int>, vector <int>, vector <int>, vector <int>);

private:
	int N;
	int M;
	vector<int> graph[50];
	vector<int> foxes;
	int dist[50][50];

	int parent[50];

	int matching[50];
	bool flag[50];


	void dfs_distance(int, int, int);
	void dfs_parent(int, int);
	bool check(int);
	bool check_root(int, int);
	bool extend_matching(int, int);

};

void FoxMeeting::dfs_parent(int x, int p) {
	parent[x] = p;
	for (int i = 0; i < graph[x].size(); ++ i)
		if (graph[x][i] != p)
			dfs_parent(graph[x][i], x);
}

bool FoxMeeting::extend_matching(int x, int maxdist) {
	for (int i = 0; i < M; ++ i) {
		int y = foxes[i];
		if (dist[x][y] <= maxdist && flag[y]) {
			flag[y] = false;
			if (matching[y] == -1 || extend_matching(matching[y], maxdist)) {
				matching[y] = x;
				return true;
			}
		}
	}
	return false;
}

bool FoxMeeting::check_root(int root, int maxdist) {
	dfs_parent(root, root);

	//cout << "passed dfs parent" << endl;
	bool gap[50];
	memset(gap, false, sizeof(gap));
	gap[root] = true;
	for (int i = 0; i < M; ++ i) {
		int pos = foxes[i];
		for (int limit = maxdist; pos != root && dist[pos][parent[pos]] <= limit; limit -= dist[pos][parent[pos]], pos = parent[pos]);
		for (pos = parent[pos]; pos != root; pos = parent[pos])
			gap[pos] = true;
	}

	/*
	for (int i = 0; i < N; ++ i)
		cout << gap[i] << " ";
	cout << endl;
	for (int i = 0; i < M; ++ i)
		cout << foxes[i] << " ";
	cout << endl;
	for (int i = 0; i < N; ++ i)
		cout << dist[i][i] << " ";
	cout << endl;
	*/
	
	memset(matching, -1, sizeof(matching));
	for (int i = 0; i < N; ++ i)
		if (gap[i]) {
			memset(flag, true, sizeof(flag));
			if (!extend_matching(i, maxdist)) return false;
		}	
	return true;
}

bool FoxMeeting::check(int maxdist) {
	for (int i = 0; i < N; ++ i) {
		//printf("check root at %d\n", i);
		if (check_root(i, maxdist))
			return true;
	}
	return false;
}

void FoxMeeting::dfs_distance(int s, int x, int distance) {
	dist[s][x] = distance;
	for (int i = 0; i < graph[x].size(); ++ i) {
		int y = graph[x][i];
		if (x != s && dist[s][y] != -1) continue;
		dfs_distance(s, y, distance + dist[x][y]);
	}
}

int FoxMeeting::maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes) {
	N = A.size() + 1;
	for (int i = 0; i < N; ++ i)
		graph[i].clear();
	memset(dist, -1, sizeof(dist));
	/*
	for (int i = 0; i < N; ++ i)
		for (int j = 0; j < N; ++ j)
			dist[i][j] = (i == j ? 0 : 1000000000);
	*/
	for (int i = 0; i < N - 1; ++ i) {
		int x = A[i] - 1; int y = B[i] - 1;
		graph[x].push_back(y);
		graph[y].push_back(x);
		dist[x][y] = dist[y][x] = L[i];
	}
	M = foxes.size();
	this->foxes.clear();
	for (int i = 0; i < M; ++ i)
		this->foxes.push_back(foxes[i] - 1);

/*
	for (int k = 0; k < N; ++ k)
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j < N; ++ j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
*/
	for (int i = 0; i < N; ++ i)
		dfs_distance(i, i, 0);	

	int left = 0;
	int right = 0;
	for (int i = 0; i < N - 1; ++ i)
		for (int j = i + 1; j < N; ++ j)
			if (dist[i][j] > right)
				right = dist[i][j];
	while (left < right) {
		//printf("(%d, %d)\n", left, right);
		int mid = (left + right) >> 1;
		if (check(mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}


double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
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
double test1() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
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
double test2() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 2, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
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
	int t0[] = {10,8,3,7,2,6,9,1,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,5,8,10,5,5,6,10,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3,4,5,6,7,8,9,10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
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
double test4() {
	int t0[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,5,7,9,10,14,17,19,20,21,24,25,28};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 107013;
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
double test5() {
	int t0[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
40718,2115,79278,88841,40966,42023};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxMeeting * obj = new FoxMeeting();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 89342;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
