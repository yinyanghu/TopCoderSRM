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

class ApplesAndOrangesEasy {
public:
	int maximumApples(int, int, vector <int>);
};

int ApplesAndOrangesEasy::maximumApples(int N, int K, vector <int> info) {
	vector<int> flag(N + 1, 0);
	for (int i = 0; i < info.size(); ++ i)
		flag[info[i]] = 1;
	vector<int> sum(N + 1, 0);
	for (int i = 1; i <= N; ++ i)
		sum[i] = sum[i - 1] + flag[i];
	int limit = K >> 1;
	for (int i = 1; i <= N; ++ i)
		if (flag[i] == 0) {
			bool ok = true;
			for (int j = i; j <= min(i + K - 1, N); ++ j)
				if (sum[j] - sum[max(0, j - K)] >= limit) {
					ok = false;
					break;
				}
			if (ok) {
				flag[i] = 1;
				for (int j = i; j <= N; ++ j) ++ sum[j];
			}
		}
	return sum[N];
}


double test0() {
	int p0 = 3;
	int p1 = 2;
	vector <int> p2;
	ApplesAndOrangesEasy * obj = new ApplesAndOrangesEasy();
	clock_t start = clock();
	int my_answer = obj->maximumApples(p0, p1, p2);
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
	int p0 = 10;
	int p1 = 3;
	int t2[] = {3, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ApplesAndOrangesEasy * obj = new ApplesAndOrangesEasy();
	clock_t start = clock();
	int my_answer = obj->maximumApples(p0, p1, p2);
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
double test2() {
	int p0 = 9;
	int p1 = 4;
	int t2[] = {1, 4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ApplesAndOrangesEasy * obj = new ApplesAndOrangesEasy();
	clock_t start = clock();
	int my_answer = obj->maximumApples(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	int p0 = 9;
	int p1 = 4;
	int t2[] = {2, 4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ApplesAndOrangesEasy * obj = new ApplesAndOrangesEasy();
	clock_t start = clock();
	int my_answer = obj->maximumApples(p0, p1, p2);
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
double test4() {
	int p0 = 23;
	int p1 = 7;
	int t2[] = {3, 2, 9, 1, 15, 23, 20, 19};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ApplesAndOrangesEasy * obj = new ApplesAndOrangesEasy();
	clock_t start = clock();
	int my_answer = obj->maximumApples(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
