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

#define infinity	1000000000

using namespace std;

class BallsSeparating {
public:
	int minOperations(vector <int>, vector <int>, vector <int>);
};

int BallsSeparating::minOperations(vector <int> red, vector <int> green, vector <int> blue) {
	int n = red.size();
	if (n < 3) return -1;
	int ans = infinity;
	vector<int> sum;
	sum.clear();
	int total = 0;
	for (int i = 0; i < n; ++ i)
	{
		sum.push_back(red[i] + green[i] + blue[i] - max(max(red[i], green[i]), blue[i]));
		total += sum[i];
	}

	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
		{
			if (i == j) continue;
			for (int k = 0; k < n; ++ k)
			{
				if (k == i || k == j) continue;
				int count = total;
				count -= sum[i] + sum[j] + sum[k];
				count += green[i] + blue[i];
				count += red[j] + blue[j];
				count += red[k] + green[k];
				if (count < ans)
					ans = count;
			}
		}
	return ans;	
}


double test0() {
	int t0[] = {1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BallsSeparating * obj = new BallsSeparating();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	int t0[] = {5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BallsSeparating * obj = new BallsSeparating();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0, p1, p2);
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
double test2() {
	int t0[] = {4, 6, 5, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 4, 6, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {6, 5, 3, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BallsSeparating * obj = new BallsSeparating();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 37;
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
	int t0[] = {7, 12, 9, 9, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 10, 8, 8, 9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8, 9, 5, 6, 13};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BallsSeparating * obj = new BallsSeparating();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 77;
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
	int t0[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BallsSeparating * obj = new BallsSeparating();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 7230607;
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
