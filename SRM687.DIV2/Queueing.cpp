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

class Queueing {
public:
	double probFirst(int, int, int, int);
};

const int maxN = 1010;

double F[maxN][maxN];

double Queueing::probFirst(int len1, int len2, int p1, int p2) {
	double p = 1.0 / (double)p1;
	double q = 1.0 / (double)p2;
	double np = 1.0 - p;
	double nq = 1.0 - q;
	memset(F, 0, sizeof(F));

	for (int i = 1; i <= len2; ++ i)
		F[0][i] = 1.0;
	for (int i = 1; i <= len1; ++ i)
		for (int j = 1; j <= len2; ++ j)
			F[i][j] = 1.0 / (1.0 - np * nq) * (F[i - 1][j] * p * nq + F[i][j - 1] * np * q + F[i - 1][j - 1] * p * q);
	return F[len1][len2];
}

/*
double Queueing::probFirst(int len1, int len2, int p1, int p2) {
	double ret = 0.0;
	double prA = 1.0 / (double)p1;
	double prB = 1.0 / (double)p2;
	double pdfA = 1.0;
	for (int i = 0; i < len1; ++ i)
		pdfA *= prA;
	double pdfB = 1.0;
	for (int i = 0; i < len2; ++ i)
		pdfB *= prB;
	double cdfB = 0.0;

	if (len1 < len2) {
		for (int k = len1; k < len2; ++ k) {
			ret += pdfA;
			pdfA = pdfA * (double)(k) / (double)(k + 1 - len1) * (1.0 - prA);
		}
	}
	else if (len1 > len2) {
		for (int k = len2; k < len1; ++ k) {
			cdfB += pdfB;
			pdfB = pdfB * (double)(k) / (double)(k + 1 - len2) * (1.0 - prB);
		}
	}
	for (int k = max(len1, len2); ; ++ k) {
		cdfB += pdfB;

		ret += pdfA * (1.0 - cdfB);

		if (k > 100000) break;

		pdfA = pdfA * (double)(k) / (double)(k + 1 - len1) * (1.0 - prA);
		pdfB = pdfB * (double)(k) / (double)(k + 1 - len2) * (1.0 - prB);
	}
	return ret;
}
*/

double eps = 1e-9;

double test0() {
	int p0 = 1;
	int p1 = 2;
	int p2 = 2;
	int p3 = 1;
	Queueing * obj = new Queueing();
	clock_t start = clock();
	double my_answer = obj->probFirst(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (abs(p4 - my_answer) > eps) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 3;
	int p2 = 3;
	int p3 = 7;
	Queueing * obj = new Queueing();
	clock_t start = clock();
	double my_answer = obj->probFirst(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.9835390946502058;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (abs(p4 - my_answer) > eps) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 7;
	int p3 = 3;
	Queueing * obj = new Queueing();
	clock_t start = clock();
	double my_answer = obj->probFirst(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.010973936899862834;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (abs(p4 - my_answer) > eps) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 12;
	int p1 = 34;
	int p2 = 56;
	int p3 = 78;
	Queueing * obj = new Queueing();
	clock_t start = clock();
	double my_answer = obj->probFirst(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.999996203228025;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (abs(p4 - my_answer) > eps) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 3;
	int p1 = 6;
	int p2 = 8;
	int p3 = 4;
	Queueing * obj = new Queueing();
	clock_t start = clock();
	double my_answer = obj->probFirst(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.5229465300297028;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (abs(p4 - my_answer) > eps) {
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
