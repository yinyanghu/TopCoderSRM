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

class SimilarUserDetection {
public:
	string haveSimilar(vector <string>);
};

string SimilarUserDetection::haveSimilar(vector <string> handles) {
	for (int i = 0; i < handles.size(); ++ i) {
		for (int j = 0; j < handles[i].size(); ++ j)
			if (handles[i][j] == '0')
				handles[i][j] = 'O';
			else if (handles[i][j] == '1' || handles[i][j] == 'l')
				handles[i][j] = 'I';
	}
	sort(handles.begin(), handles.end());
	for (int i = 1; i < handles.size(); ++ i)
		if (handles[i] == handles[i - 1]) return "Similar handles found";
	return "Similar handles not found";
}


double test0() {
	string t0[] = {"top", "coder", "TOPCODER", "TOPC0DER"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SimilarUserDetection * obj = new SimilarUserDetection();
	clock_t start = clock();
	string my_answer = obj->haveSimilar(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Similar handles found";
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
	string t0[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SimilarUserDetection * obj = new SimilarUserDetection();
	clock_t start = clock();
	string my_answer = obj->haveSimilar(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Similar handles not found";
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
	string t0[] = {"same", "same", "same", "different"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SimilarUserDetection * obj = new SimilarUserDetection();
	clock_t start = clock();
	string my_answer = obj->haveSimilar(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Similar handles found";
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
	string t0[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SimilarUserDetection * obj = new SimilarUserDetection();
	clock_t start = clock();
	string my_answer = obj->haveSimilar(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Similar handles found";
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
	string t0[] = {"i23", "123", "456", "789", "000", "o", "O"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SimilarUserDetection * obj = new SimilarUserDetection();
	clock_t start = clock();
	string my_answer = obj->haveSimilar(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Similar handles not found";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
