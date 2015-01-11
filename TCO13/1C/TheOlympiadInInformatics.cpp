#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cstring>
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

class TheOlympiadInInformatics {
public:
	int find(vector <int>, int);
};



int TheOlympiadInInformatics::find(vector <int> sums, int k) {
	int n = sums.size();	
	int maxkey = 0;
	for (int i = 0; i < n; ++ i)
		maxkey = max(maxkey, sums[i]);

	long long K = (long long)k;
	int left = 0, right = maxkey + 1;
	while (left + 1 < right)
	{
		//cout << "[" << left << ", " << right << ")" << endl;
		int mid = (left + right) >> 1;
		long long total = 0;
		for (int i = 0; i < n; ++ i)
			total += (long long)(sums[i] / mid);
		if (total <= K)
			right = mid;
		else
			left = mid;
	}
//	cout << "[" << left << ", " << right << ")" << endl;
	return left;	
}


double test0() {
	int t0[] = {4, 7, 0, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 0;
	TheOlympiadInInformatics * obj = new TheOlympiadInInformatics();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {4, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	TheOlympiadInInformatics * obj = new TheOlympiadInInformatics();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {999999999};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000000000;
	TheOlympiadInInformatics * obj = new TheOlympiadInInformatics();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {95, 23, 87, 23, 82, 78, 59, 44, 12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 70;
	TheOlympiadInInformatics * obj = new TheOlympiadInInformatics();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
